//
// Created by Павло Коваль on 25.06.2022.
//

#ifndef BLOCKCHAIN_KEYPAIR_H
#define BLOCKCHAIN_KEYPAIR_H

#include <openssl/rsa.h>
#include <openssl/pem.h>

#include <string>
#include <utility>


class KeyPair {
private:
public:
    std::string fileName;

public:
    KeyPair() = delete;

    explicit KeyPair(std::string fileName): fileName(std::move(fileName)) { }

    void generateKeyPair()
    {
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
        PEM_write_bio_RSAPublicKey(bp_public, r);

        bp_private = BIO_new_file(std::string(fileName + "_private.pem").c_str(), "w+");
        PEM_write_bio_RSAPrivateKey(bp_private, r, nullptr, nullptr, 0, nullptr, nullptr);

        BIO_free_all(bp_public);
        BIO_free_all(bp_private);

        RSA_free(r);
        BN_free(bne);
    }

};


#endif //BLOCKCHAIN_KEYPAIR_H
