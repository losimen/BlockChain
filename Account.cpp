//
// Created by Павло Коваль on 17.07.2022.
//

#include "Account.h"

int Account::getReputation() const {
    return reputation;
}

void Account::setReputation(int reputation) {
    Account::reputation = reputation;
}

const KeyPair &Account::getKeyPair() const {
    return keyPair;
}

void Account::setKeyPair(const KeyPair &keyPair) {
    Account::keyPair = keyPair;
}

void Account::createNewAccount() {
    // TODO: in future cratedAt has to be field with hash of current block

    createdAt = "hash";

    keyPair.setFileName("newAccount");
    keyPair.generateKeyPair();
    reputation = 0;
}

void Account::createNewAccount(const KeyPair &keyPair) {
    // TODO: in future cratedAt has to be field with hash of current block

    createdAt = "hash";

    Account::keyPair = keyPair;
    reputation = 0;
}

void Account::connectExistingAccount() {
    // TODO: in future get info from the block

    // in future reputation and cratedAt has to be gathered from the block
    reputation = 1;
    createdAt = "hash";
}

int Account::getLifeTime() const {
    // TODO: function has to count how many block account live

    return 0;
}


