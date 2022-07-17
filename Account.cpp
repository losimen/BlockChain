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
    keyPair.setFileName("newAccount");
    keyPair.generateKeyPair();
    reputation = 0;
}

void Account::createNewAccount(const KeyPair &keyPair) {
    Account::keyPair = keyPair;
    reputation = 0;
}


