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
    Account();

    KeyPair createNewAccount();
    KeyPair createNewAccount(const KeyPair &keyPair);

    int getReputation() const;
    const KeyPair &getKeyPair() const;
    int getLifeTime() const;

    void setKeyPair(const KeyPair &keyPair);
};


#endif //BLOCKCHAIN_ACCOUNT_H
