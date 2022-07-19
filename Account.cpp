//
// Created by Павло Коваль on 17.07.2022.
//

#include "Account.h"

int Account::getReputation() const {
    return getLifeTime()/reputationCourse;
}

const KeyPair &Account::getKeyPair() const {
    return keyPair_;
}

void Account::setKeyPair(const KeyPair &keyPair) {
    Account::keyPair_ = keyPair;
}

void Account::createNewAccount() {
    // TODO: in future cratedAt has to be field with hash of current block
    keyPair_.setFileName("newAccount");

    keyPair_.generateKeyPair();
    while (keyPair_.getPublicKeyStr().substr(0, 15) != std::string(15, '0'))
    {
        std::cout << keyPair_.getPublicKeyStr().substr(0, 15) << " "
                  << std::string(15, '0') << std::endl << std::endl;
        keyPair_.generateKeyPair();
    }
}

void Account::createNewAccount(const KeyPair &keyPair) {
    // TODO: in future cratedAt has to be field with hash of current block
    if (keyPair_.getPublicKeyStr().substr(0, 15) != std::string(15, '0'))
        throw std::invalid_argument("Your public token doesn't start with 15-th zeros");

    Account::keyPair_ = keyPair;
}

void Account::connectExistingAccount() {
    // TODO: in future get info from the block
    // in future and createdAt_ has to be gathered from the block

}

int Account::getLifeTime() const {
    // TODO: function has to count how many block account live

    return 0;
}


