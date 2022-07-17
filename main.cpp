#include <iostream>

#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

#include "KeyPair.h"

void Encrypt(KeyPair &keyPair, const std::string &toEncrypt, std::string &encryptMsg){
    unsigned char *encryptMsg_, *plainMsg;

    int inlen = int(toEncrypt.size());
    int outlen;

    RSA* pubKey = keyPair.getPublicKey();

    int key_size = RSA_size(pubKey);

    encryptMsg_ = (unsigned char *)malloc(key_size);
    plainMsg = reinterpret_cast<unsigned char*>(const_cast<char*>(toEncrypt.c_str()));

    OpenSSL_add_all_algorithms();
    outlen = RSA_public_encrypt(inlen, plainMsg, encryptMsg_, pubKey, RSA_PKCS1_PADDING);

    encryptMsg = std::string((reinterpret_cast<char*>(encryptMsg_)), outlen);
}

void Decrypt(KeyPair &keyPair, std::string &toDecrpyt){
    unsigned char *decrpytMsg, *encodeMsg;
    RSA* privKey = keyPair.getPrivateKey();
    int key_size = RSA_size(privKey);

    decrpytMsg = (unsigned char *)malloc(key_size);
    encodeMsg = reinterpret_cast<unsigned char*>(const_cast<char*>(toDecrpyt.c_str()));

    RSA_private_decrypt(int(toDecrpyt.size()), encodeMsg, decrpytMsg, privKey, RSA_PKCS1_PADDING);
    toDecrpyt = std::string((reinterpret_cast<char*>(decrpytMsg)));
}

int main() {
    KeyPair el("l");
    el.generateKeyPair();

    std::string plainText = "Hello this is Pavlo";
    std::string encryptedMsg;

    Encrypt(el, plainText, encryptedMsg);
    Decrypt(el, encryptedMsg);

    std::cout << encryptedMsg << std::endl;

    return 0;
}
