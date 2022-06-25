//
// Created by Павло Коваль on 25.06.2022.
//

#include "KeyPair.h"

void KeyPair::generateKeyPair() const {
    RSA	*r;
    BIGNUM	*bne;
    BIO	*bp_public, *bp_private;

    int	bits = 2048;
    unsigned long e = RSA_F4;

    bne = BN_new();
    BN_set_word(bne,e);

    r = RSA_new();
    RSA_generate_key_ex(r, bits, bne, nullptr);

    bp_public = BIO_new_file(std::string(fileName + "_public.pem").c_str(), "w+");
    bp_private = BIO_new_file(std::string(fileName + "_private.pem").c_str(), "w+");

    PEM_write_bio_RSAPublicKey(bp_public, r);
    PEM_write_bio_RSAPrivateKey(bp_private, r, nullptr, nullptr, 0, nullptr, nullptr);

    BIO_free_all(bp_public);
    BIO_free_all(bp_private);

    RSA_free(r);
    BN_free(bne);
}

EVP_PKEY *KeyPair::getPublicKey() {
    EVP_PKEY *ret = EVP_PKEY_new();
    FILE *pkeyFile = fopen(std::string(fileName + "_public.pem").c_str(), "r");

    if (pkeyFile == nullptr)
        throw std::invalid_argument("There is no such file");

    return PEM_read_PUBKEY(pkeyFile, &ret, nullptr, nullptr);
}

EVP_PKEY *KeyPair::getPrivateKey() {
    EVP_PKEY *ret = EVP_PKEY_new();
    FILE *pkeyFile = fopen(std::string(fileName + "_private.pem").c_str(), "r");

    if (pkeyFile == nullptr)
        throw std::invalid_argument("There is no such file");

    return PEM_read_PrivateKey(pkeyFile, &ret, nullptr, nullptr);
}

std::pair<EVP_PKEY *, EVP_PKEY *> KeyPair::getKeyRSApair() {

    return {getPublicKey(),getPublicKey()};
}
