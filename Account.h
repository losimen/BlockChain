//
// Created by Павло Коваль on 17.07.2022.
//

#ifndef BLOCKCHAIN_ACCOUNT_H
#define BLOCKCHAIN_ACCOUNT_H

#include "KeyPair.h"
#include <iostream>

class Account {
private:
    int reputation;
    KeyPair keyPair;

public:
    explicit Account(const std::string &keysFileName): reputation(0), keyPair(KeyPair(keysFileName)) { }

    void createNewAccount();
    void createNewAccount(const KeyPair &keyPair);

    int getReputation() const;
    const KeyPair &getKeyPair() const;

    void setReputation(int reputation);
    void setKeyPair(const KeyPair &keyPair);
};


#endif //BLOCKCHAIN_ACCOUNT_H
