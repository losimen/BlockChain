#include <iostream>

#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

#include "KeyPair.h"


int Encrypt(KeyPair &keyPair, const std::string &toEncrypt, std::string &encodeTxt){

    unsigned char *ctext, *ptext;

    int inlen = int(toEncrypt.size());
    int outlen;

    RSA* pubKey = keyPair.getPublicKey();

    int key_size = RSA_size(pubKey);

    ctext = (unsigned char *)malloc(key_size);
    ptext = reinterpret_cast<unsigned char*>(const_cast<char*>(toEncrypt.c_str()));

    OpenSSL_add_all_algorithms();
    outlen = RSA_public_encrypt(inlen, ptext, ctext, pubKey, RSA_PKCS1_PADDING);

    encodeTxt = std::string((reinterpret_cast<char*>(ctext)));

    return outlen;
}

void Decrypt(KeyPair &keyPair, int inlen, std::string &toEncode){
    unsigned char *ptext, *ctext;
    int outlen;

    RSA* privKey = keyPair.getPrivateKey();

    int key_size = RSA_size(privKey);

    ptext = (unsigned char *)malloc(key_size);
    ctext = reinterpret_cast<unsigned char*>(const_cast<char*>(toEncode.c_str()));

    outlen = RSA_private_decrypt(inlen, ctext, ptext, privKey, RSA_PKCS1_PADDING);

    std::string a = ERR_error_string(ERR_get_error(), nullptr);

    std::cout << outlen << ptext << std::endl;
}

int main() {
    KeyPair el("l");
    el.generateKeyPair();

    std::string plainText = "Hello this is";
    std::string encodeTxt;

    int msgSize = Encrypt(el, plainText, encodeTxt);
    Decrypt(el, msgSize, encodeTxt);

    return 0;
}
