//
// Created by Павло Коваль on 18.07.2022.
//

#include "Security.h"

std::string Security::encryptPublicMSG(KeyPair &keyPair, const std::string &toEncrypt) {
    std::string encryptResult;

    unsigned char *encryptMsg_, *plainMsg;
    int encryptMsgLen;

    RSA* publicKey = keyPair.getPublicKey();

    int key_size = RSA_size(publicKey);

    encryptMsg_ = (unsigned char *)malloc(key_size);
    plainMsg = reinterpret_cast<unsigned char*>(const_cast<char*>(toEncrypt.c_str()));

    OpenSSL_add_all_algorithms();
    encryptMsgLen = RSA_public_encrypt(int(toEncrypt.size()), plainMsg, encryptMsg_, publicKey, RSA_PKCS1_PADDING);

    encryptResult = std::string((reinterpret_cast<char*>(encryptMsg_)), encryptMsgLen);

    RSA_free(publicKey);

    return encryptResult;
}

std::string Security::encryptPrivateMSG(KeyPair &keyPair, const std::string &toEncrypt) {
    std::string encryptResult;

    unsigned char *encryptMsg_, *plainMsg;
    int encryptMsgLen;

    RSA* privateKey = keyPair.getPrivateKey();

    int key_size = RSA_size(privateKey);

    encryptMsg_ = (unsigned char *)malloc(key_size);
    plainMsg = reinterpret_cast<unsigned char*>(const_cast<char*>(toEncrypt.c_str()));

    OpenSSL_add_all_algorithms();
    encryptMsgLen = RSA_private_encrypt(int(toEncrypt.size()), plainMsg, encryptMsg_, privateKey, RSA_PKCS1_PADDING);

    encryptResult = std::string((reinterpret_cast<char*>(encryptMsg_)), encryptMsgLen);

    RSA_free(privateKey);

    return encryptResult;
}

std::string Security::decryptPrivateMSG(KeyPair &keyPair, const std::string &toDecrpyt) {
    std::string decryptionResult;

    unsigned char *decryptMsg, *encodeMsg;
    RSA* privateKey = keyPair.getPrivateKey();
    int key_size = RSA_size(privateKey);

    decryptMsg = (unsigned char *)malloc(key_size);
    encodeMsg = reinterpret_cast<unsigned char*>(const_cast<char*>(toDecrpyt.c_str()));

    auto lenOfMsg = RSA_private_decrypt(int(toDecrpyt.size()), encodeMsg, decryptMsg, privateKey, RSA_PKCS1_PADDING);
    decryptionResult = std::string((reinterpret_cast<char*>(decryptMsg)), lenOfMsg);

    RSA_free(privateKey);

    return decryptionResult;
}

std::string Security::decryptPublicMSG(KeyPair &keyPair, const std::string &toDecrpyt) {
    std::string decryptionResult;

    unsigned char *decryptMsg, *encodeMsg;
    RSA* publicKey = keyPair.getPublicKey();
    int key_size = RSA_size(publicKey);

    decryptMsg = (unsigned char *)malloc(key_size);
    encodeMsg = reinterpret_cast<unsigned char*>(const_cast<char*>(toDecrpyt.c_str()));

    auto lenOfMsg = RSA_public_decrypt(int(toDecrpyt.size()), encodeMsg, decryptMsg, publicKey, RSA_PKCS1_PADDING);
    decryptionResult = std::string((reinterpret_cast<char*>(decryptMsg)), lenOfMsg);

    RSA_free(publicKey);

    return decryptionResult;
}

bool Security::isKeyPairValid(KeyPair &keyPair) {
    try {
        const std::string originMsg ("originMsg");

        std::string encryptedMsg = encryptPublicMSG(keyPair, originMsg);
        std::string decryptedMSg = decryptPrivateMSG(keyPair, encryptedMsg);

        return originMsg == decryptedMSg;
    }
    catch (...) {
        return false;
    }
}

std::string Security::SHA256generator(const std::string &input_) {
    auto* input = reinterpret_cast<unsigned char*>(const_cast<char*>(input_.c_str()));
    unsigned char md[SHA256_DIGEST_LENGTH];

    std::string result ("none");
    SHA256_CTX context;

    if(!SHA256_Init(&context))
        return result;

    if(!SHA256_Update(&context, (unsigned char*)input, strlen((char*)input)))
        return result;

    if(!SHA256_Final(md, &context))
        return result;

    result.clear();
    for (unsigned char i : md) {
        char buffer [4];
        snprintf ( buffer, 4, "%02x", i );

        result += buffer;
    }

    return result;
}

std::string Security::encryptPublicMSG(RSA *publicKey, const std::string &toEncrypt) {
    std::string encryptResult;

    unsigned char *encryptMsg_, *plainMsg;
    int encryptMsgLen;

    int key_size = RSA_size(publicKey);

    encryptMsg_ = (unsigned char *)malloc(key_size);
    plainMsg = reinterpret_cast<unsigned char*>(const_cast<char*>(toEncrypt.c_str()));

    OpenSSL_add_all_algorithms();
    encryptMsgLen = RSA_public_encrypt(int(toEncrypt.size()), plainMsg, encryptMsg_, publicKey, RSA_PKCS1_PADDING);

    encryptResult = std::string((reinterpret_cast<char*>(encryptMsg_)), encryptMsgLen);

    RSA_free(publicKey);

    return encryptResult;
}

std::string Security::encryptPrivateMSG(RSA *privateKey, const std::string &toEncrypt) {
    std::string encryptResult;

    unsigned char *encryptMsg_, *plainMsg;
    int encryptMsgLen;

    int key_size = RSA_size(privateKey);

    encryptMsg_ = (unsigned char *)malloc(key_size);
    plainMsg = reinterpret_cast<unsigned char*>(const_cast<char*>(toEncrypt.c_str()));

    OpenSSL_add_all_algorithms();
    encryptMsgLen = RSA_private_encrypt(int(toEncrypt.size()), plainMsg, encryptMsg_, privateKey, RSA_PKCS1_PADDING);

    encryptResult = std::string((reinterpret_cast<char*>(encryptMsg_)), encryptMsgLen);

    RSA_free(privateKey);

    return encryptResult;
}

std::string Security::decryptPrivateMSG(RSA *privateKey, const std::string &toDecrpyt) {
    std::string decryptionResult;

    unsigned char *decryptMsg, *encodeMsg;
    int key_size = RSA_size(privateKey);

    decryptMsg = (unsigned char *)malloc(key_size);
    encodeMsg = reinterpret_cast<unsigned char*>(const_cast<char*>(toDecrpyt.c_str()));

    auto lenOfMsg = RSA_private_decrypt(int(toDecrpyt.size()), encodeMsg, decryptMsg, privateKey, RSA_PKCS1_PADDING);
    decryptionResult = std::string((reinterpret_cast<char*>(decryptMsg)), lenOfMsg);

    RSA_free(privateKey);

    return decryptionResult;
}

std::string Security::decryptPublicMSG(RSA *publicKey, const std::string &toDecrpyt) {
    std::string decryptionResult;

    unsigned char *decryptMsg, *encodeMsg;
    int key_size = RSA_size(publicKey);

    decryptMsg = (unsigned char *)malloc(key_size);
    encodeMsg = reinterpret_cast<unsigned char*>(const_cast<char*>(toDecrpyt.c_str()));

    auto lenOfMsg = RSA_public_decrypt(int(toDecrpyt.size()), encodeMsg, decryptMsg, publicKey, RSA_PKCS1_PADDING);
    decryptionResult = std::string((reinterpret_cast<char*>(decryptMsg)), lenOfMsg);

    RSA_free(publicKey);

    return decryptionResult;
}

std::string Security::SHA256generatorRandom() {
    auto* input = reinterpret_cast<unsigned char*>(const_cast<char*>(Security::getRandomString_().c_str()));
    unsigned char md[SHA256_DIGEST_LENGTH];

    std::string result ("none");
    SHA256_CTX context;

    if(!SHA256_Init(&context))
        return result;

    if(!SHA256_Update(&context, (unsigned char*)input, strlen((char*)input)))
        return result;

    if(!SHA256_Final(md, &context))
        return result;

    result.clear();
    for (unsigned char i : md) {
        char buffer [4];
        snprintf ( buffer, 4, "%02x", i );

        result += buffer;
    }

    return result;
}

std::string Security::getRandomString_() {
    const int length = 1000;
    std::string result;
    std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789/][';.,=+-_)(*&^%$#@!~`";

    // get random number C++11
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, int(chars.length()) - 1);

    for (int i = 0; i < length; i++) {
        result += chars[dis(gen)];
    }

    return result;
}
