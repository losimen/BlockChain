//
// Created by Павло Коваль on 25.06.2022.
//

#include "KeyPair.h"

void KeyPair::generateKeyPair() const {
    char secret[] = "loh6";

    RSA * rsa = nullptr;
    unsigned long bits = 1024;
    FILE * privKey_file = nullptr, *pubKey_file = nullptr;

    const EVP_CIPHER *cipher = nullptr;

    privKey_file = fopen(std::string(fileName + "_private.key").c_str(), "wb");
    pubKey_file = fopen(std::string(fileName + "_public.key").c_str(), "wb");

    rsa = RSA_generate_key(bits, RSA_F4, nullptr, nullptr);

    cipher = EVP_get_cipherbyname("bf-ofb");

    PEM_write_RSAPrivateKey(privKey_file, rsa, cipher, nullptr, 0, nullptr, secret);
    PEM_write_RSAPublicKey(pubKey_file, rsa);

    RSA_free(rsa);
    fclose(privKey_file);
    fclose(pubKey_file);
}

RSA *KeyPair::getPublicKey() const {
    RSA * pubKey = nullptr;
    FILE * pubKey_file = nullptr;

    pubKey_file = fopen(std::string(fileName + "_public.key").c_str(), "rb");
    pubKey = PEM_read_RSAPublicKey(pubKey_file, nullptr, nullptr, nullptr);
    fclose(pubKey_file);

    return pubKey;
}

RSA *KeyPair::getPrivateKey() const {
    char secret[] = "loh6";

    RSA * privKey = nullptr;
    FILE * privKey_file;

    OpenSSL_add_all_algorithms();
    privKey_file = fopen(std::string(fileName + "_private.key").c_str(), "rb");
    privKey = PEM_read_RSAPrivateKey(privKey_file, nullptr, nullptr, secret);
    fclose(privKey_file);

    return privKey;
}

const std::string &KeyPair::getFileName() const {
    return fileName;
}

void KeyPair::setFileName(const std::string &fileName) {
    KeyPair::fileName = fileName;
}
