//
// Created by Павло Коваль on 25.06.2022.
//

#include "KeyPair.h"

void KeyPair::generateKeyPair() const {
    char secret[] = "loh6";

    RSA * rsa = NULL;
    unsigned long bits = 1024;
    FILE * privKey_file = NULL, *pubKey_file = NULL;

    const EVP_CIPHER *cipher = NULL;

    privKey_file = fopen("private.key", "wb");
    pubKey_file = fopen("public.key", "wb");

    rsa = RSA_generate_key(bits, RSA_F4, NULL, NULL);

    cipher = EVP_get_cipherbyname("bf-ofb");

    PEM_write_RSAPrivateKey(privKey_file, rsa, cipher, NULL, 0, NULL, secret);
    PEM_write_RSAPublicKey(pubKey_file, rsa);

    RSA_free(rsa);
    fclose(privKey_file);
    fclose(pubKey_file);
}

RSA *KeyPair::getPublicKey() {
    RSA * pubKey = NULL;
    FILE * pubKey_file = NULL;

    pubKey_file = fopen("public.key", "rb");
    pubKey = PEM_read_RSAPublicKey(pubKey_file, NULL, NULL, NULL);
    fclose(pubKey_file);

    return pubKey;
}

RSA *KeyPair::getPrivateKey() {
    char secret[] = "loh6";

    RSA * privKey = NULL;
    FILE * privKey_file;
    unsigned char *ptext, *ctext;
    int outlen;

    OpenSSL_add_all_algorithms();
    privKey_file = fopen("private.key", "rb");
    privKey = PEM_read_RSAPrivateKey(privKey_file, nullptr, nullptr, secret);
    fclose(privKey_file);

    return privKey;
}
