//
// Created by Павло Коваль on 25.06.2022.
//

#include "KeyPair.h"

void KeyPair::generateKeyPair() const {
    char secret[] = "loh6";
    unsigned long bits = 2048;

    FILE * privKey_file, *pubKey_file;
    RSA *rsa;
    BIGNUM *bn;

    bn = BN_new();
    BN_set_word(bn, RSA_F4);

    const EVP_CIPHER *cipher;

    privKey_file = fopen(std::string(fileName + "_private.key").c_str(), "wb");
    pubKey_file = fopen(std::string(fileName + "_public.key").c_str(), "wb");

    rsa = RSA_new();

    RSA_generate_key_ex(rsa, bits, bn, nullptr);

    cipher = EVP_get_cipherbyname("bf-ofb");

    PEM_write_RSAPrivateKey(privKey_file, rsa, cipher, nullptr, 0, nullptr, secret);
    PEM_write_RSAPublicKey(pubKey_file, rsa);

    RSA_free(rsa);
    fclose(privKey_file);
    fclose(pubKey_file);
}

RSA *KeyPair::getPublicKey() const {
    RSA * pubKey;
    FILE * pubKey_file;

    pubKey_file = fopen(std::string(fileName + "_public.key").c_str(), "rb");
    pubKey = PEM_read_RSAPublicKey(pubKey_file, nullptr, nullptr, nullptr);
    fclose(pubKey_file);

    return pubKey;
}

RSA *KeyPair::getPrivateKey() const {
    char secret[] = "loh6";

    RSA * privKey;
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

#include <iostream>

std::string KeyPair::getPublicKeyStr() const {
    std::ifstream t(std::string(fileName + "_public.key"));
    std::stringstream buffer;
    buffer << t.rdbuf();


    std::string publicKey = buffer.str();
    publicKey.erase(std::remove(publicKey.begin(), publicKey.end(), '\n'), publicKey.cend());

    return {publicKey.begin() + 30, publicKey.end() - 30};
}
