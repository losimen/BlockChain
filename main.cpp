#include <iostream>

#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

#include "KeyPair.h"

void Encrypt(KeyPair &keyPair, const std::string &toEncrypt, std::string &encryptMsg){
    unsigned char *encryptMsg_, *plainMsg;
    int encryptMsgLen;

    RSA* pubKey = keyPair.getPublicKey();

    int key_size = RSA_size(pubKey);

    encryptMsg_ = (unsigned char *)malloc(key_size);
    plainMsg = reinterpret_cast<unsigned char*>(const_cast<char*>(toEncrypt.c_str()));

    OpenSSL_add_all_algorithms();
    encryptMsgLen = RSA_public_encrypt(int(toEncrypt.size()), plainMsg, encryptMsg_, pubKey, RSA_PKCS1_PADDING);

    encryptMsg = std::string((reinterpret_cast<char*>(encryptMsg_)), encryptMsgLen);
}

void Decrypt(KeyPair &keyPair, std::string &toDecrpyt){
    unsigned char *decryptMsg, *encodeMsg;
    RSA* privateKey = keyPair.getPrivateKey();
    int key_size = RSA_size(privateKey);

    decryptMsg = (unsigned char *)malloc(key_size);
    encodeMsg = reinterpret_cast<unsigned char*>(const_cast<char*>(toDecrpyt.c_str()));

    RSA_private_decrypt(int(toDecrpyt.size()), encodeMsg, decryptMsg, privateKey, RSA_PKCS1_PADDING);
    toDecrpyt = std::string((reinterpret_cast<char*>(decryptMsg)));
}

int main() {
    KeyPair key("l");
    key.generateKeyPair();

    std::string plainText = "Hello this is Pavlo";
    std::string encryptedMsg;

    Encrypt(key, plainText, encryptedMsg);
    Decrypt(key, encryptedMsg);

    std::cout << encryptedMsg << std::endl;

    return 0;
}
