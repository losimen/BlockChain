//
// Created by Павло Коваль on 17.07.2022.
//

#ifndef BLOCKCHAIN_ACCOUNT_H
#define BLOCKCHAIN_ACCOUNT_H

#include "KeyPair.h"
#include <iostream>

const int reputationCourse = 100;

class Account {
private:
    KeyPair keyPair_;

public:
    explicit Account(const std::string &keysFileName):
        keyPair_(KeyPair(keysFileName))
        {}

    void createNewAccount();
    void createNewAccount(const KeyPair &keyPair);

    void createNewPublicPost();
    void createNewPrivatePost();

    void connectExistingAccount();

    int getReputation() const;
    const KeyPair &getKeyPair() const;
    int getLifeTime() const;

    void setReputation(int reputation);
    void setKeyPair(const KeyPair &keyPair);
};


#endif //BLOCKCHAIN_ACCOUNT_H
