//
// Created by Павло Коваль on 25.06.2022.
//

#ifndef BLOCKCHAIN_KEYPAIR_H
#define BLOCKCHAIN_KEYPAIR_H

#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/sha.h>

#include <cstdio>
#include <string>
#include <utility>
#include <fstream>
#include <sstream>
#include <random>


class KeyPair {
private:
public:
    std::string fileName;

public:
    KeyPair():
        fileName(std::string("none"))
        {}

    explicit KeyPair(std::string fileName):
        fileName(std::move(fileName))
        {}

    void generateKeyPair() const;

    void setFileName(const std::string &fileName);

    const std::string &getFileName() const;
    RSA *getPublicKey() const;
    RSA *getPrivateKey() const;

    std::string getPublicKeyStr() const;
};


#endif //BLOCKCHAIN_KEYPAIR_H
