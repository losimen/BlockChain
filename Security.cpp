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
