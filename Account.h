//
// Created by Павло Коваль on 17.07.2022.
//

#ifndef BLOCKCHAIN_ACCOUNT_H
#define BLOCKCHAIN_ACCOUNT_H

#include "KeyPair.h"
#include <iostream>


class Account {
private:
    static const int REPUTATION_COURSE;
    static volatile const int SECURITY_LEVEL;

    KeyPair keyPair_;
public:
    Account();

    KeyPair createNewAccount();
    KeyPair createNewAccount(const KeyPair &keyPair);

    static int getReputation(const std::string &publicKey, const json& blockChain) ;
    static int getLifeTime(const std::string &publicKey, json blockChain) ;

    const KeyPair &getKeyPair() const;

    void setKeyPair(const KeyPair &keyPair);
};


#endif //BLOCKCHAIN_ACCOUNT_H
