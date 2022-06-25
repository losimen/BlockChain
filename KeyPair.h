//
// Created by Павло Коваль on 25.06.2022.
//

#ifndef BLOCKCHAIN_KEYPAIR_H
#define BLOCKCHAIN_KEYPAIR_H

#include <openssl/rsa.h>
#include <openssl/pem.h>

#include <stdio.h>
#include <string>
#include <utility>

class KeyPair {
private:
public:
    std::string fileName;

public:
    KeyPair() = delete;

    explicit KeyPair(std::string fileName): fileName(std::move(fileName)) { }

    void generateKeyPair() const;

    void getPublicKey();
    void getPrivateKey();
};


#endif //BLOCKCHAIN_KEYPAIR_H
