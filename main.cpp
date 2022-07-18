#include <iostream>

#include "KeyPair.h"
#include "base64.h"

void encryptPublic(KeyPair &keyPair, const std::string &toEncrypt, std::string &encryptMsg){
    unsigned char *encryptMsg_, *plainMsg;
    int encryptMsgLen;

    RSA* publicKey = keyPair.getPublicKey();

    int key_size = RSA_size(publicKey);

    encryptMsg_ = (unsigned char *)malloc(key_size);
    plainMsg = reinterpret_cast<unsigned char*>(const_cast<char*>(toEncrypt.c_str()));

    OpenSSL_add_all_algorithms();
    encryptMsgLen = RSA_public_encrypt(int(toEncrypt.size()), plainMsg, encryptMsg_, publicKey, RSA_PKCS1_PADDING);

    encryptMsg = std::string((reinterpret_cast<char*>(encryptMsg_)), encryptMsgLen);

    RSA_free(publicKey);
}


void encryptPrivate(KeyPair &keyPair, const std::string &toEncrypt, std::string &encryptMsg){
    unsigned char *encryptMsg_, *plainMsg;
    int encryptMsgLen;

    RSA* privateKey = keyPair.getPrivateKey();

    int key_size = RSA_size(privateKey);

    encryptMsg_ = (unsigned char *)malloc(key_size);
    plainMsg = reinterpret_cast<unsigned char*>(const_cast<char*>(toEncrypt.c_str()));

    OpenSSL_add_all_algorithms();
    encryptMsgLen = RSA_private_encrypt(int(toEncrypt.size()), plainMsg, encryptMsg_, privateKey, RSA_PKCS1_PADDING);

    encryptMsg = std::string((reinterpret_cast<char*>(encryptMsg_)), encryptMsgLen);

    RSA_free(privateKey);
}


void decryptPrivate(KeyPair &keyPair, std::string &toDecrpyt){
    unsigned char *decryptMsg, *encodeMsg;
    RSA* privateKey = keyPair.getPrivateKey();
    int key_size = RSA_size(privateKey);

    decryptMsg = (unsigned char *)malloc(key_size);
    encodeMsg = reinterpret_cast<unsigned char*>(const_cast<char*>(toDecrpyt.c_str()));

    auto lenOfMsg = RSA_private_decrypt(int(toDecrpyt.size()), encodeMsg, decryptMsg, privateKey, RSA_PKCS1_PADDING);
    toDecrpyt = std::string((reinterpret_cast<char*>(decryptMsg)), lenOfMsg);

    RSA_free(privateKey);
}


void decryptPublic(KeyPair &keyPair, std::string &toDecrpyt){
    unsigned char *decryptMsg, *encodeMsg;
    RSA* publicKey = keyPair.getPublicKey();
    int key_size = RSA_size(publicKey);

    decryptMsg = (unsigned char *)malloc(key_size);
    encodeMsg = reinterpret_cast<unsigned char*>(const_cast<char*>(toDecrpyt.c_str()));

    auto lenOfMsg = RSA_public_decrypt(int(toDecrpyt.size()), encodeMsg, decryptMsg, publicKey, RSA_PKCS1_PADDING);
    toDecrpyt = std::string((reinterpret_cast<char*>(decryptMsg)), lenOfMsg);

    RSA_free(publicKey);
}


int main() {
    KeyPair key("l");
    key.generateKeyPair();

    std::string plainText = "Hello this is Pavlo";
    std::string encryptedMsg;

    std::cout << "private msg: ";
    encryptPublic(key, plainText, encryptedMsg);

    std::cout << encryptedMsg.length() << std::endl;
    std::string temp = base64_encode(reinterpret_cast<unsigned char*>(const_cast<char*>(encryptedMsg.c_str())), encryptedMsg.size());

    encryptedMsg.clear();
    encryptedMsg = base64_decode(temp);

    decryptPrivate(key, encryptedMsg);
    std::cout << encryptedMsg << std::endl;
    std::cout << std::endl << std::endl;

    encryptedMsg.clear();

    std::cout << "public msg: ";
    encryptPrivate(key, plainText, encryptedMsg);
    decryptPublic(key, encryptedMsg);
    std::cout << encryptedMsg << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << key.getPublicKeyStr() << std::endl;

    return 0;
}
