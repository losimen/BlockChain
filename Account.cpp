//
// Created by Павло Коваль on 17.07.2022.
//

#include "Account.h"

const int Account::REPUTATION_COURSE = 100;
volatile const int Account::SECURITY_LEVEL = 0;


Account::Account() = default;

int Account::getReputation(const std::string &publicKey, const json& blockChain) const {
    return getLifeTime(publicKey, blockChain) / REPUTATION_COURSE;
}

const KeyPair &Account::getKeyPair() const {
    return keyPair_;
}

void Account::setKeyPair(const KeyPair &keyPair) {
    Account::keyPair_ = keyPair;
}

KeyPair Account::createNewAccount() {
    keyPair_.setFileName("newAccount");

    if (!bool(SECURITY_LEVEL))
        return keyPair_;

    keyPair_.generateKeyPair();
    while (keyPair_.getPublicKeyStr().substr(0, SECURITY_LEVEL) != std::string(SECURITY_LEVEL, '0'))
    {
        std::cout << keyPair_.getPublicKeyStr().substr(0, SECURITY_LEVEL) << " "
                  << std::string(15, '0') << std::endl << std::endl;
        keyPair_.generateKeyPair();
    }
}

KeyPair Account::createNewAccount(const KeyPair &keyPair) {
    keyPair_ = keyPair;

    std::cout << keyPair_.getPublicKeyStr().substr(0, SECURITY_LEVEL) << " " << std::string(SECURITY_LEVEL, '0') << std::endl;

    if (!bool(SECURITY_LEVEL))
        return keyPair_;

    if (keyPair_.getPublicKeyStr().substr(0, SECURITY_LEVEL) != std::string(SECURITY_LEVEL, '0'))
        throw std::invalid_argument("Your public token doesn't match security level");

    Account::keyPair_ = keyPair;
}

int Account::getLifeTime(const std::string& publicKey, json blockChain) const {
    int lifeTime = 0;

    std::reverse(blockChain.begin(), blockChain.end());

    int temp = 0;
    for (auto blockIt = blockChain.begin(); blockIt != blockChain.end(); blockIt++) {
        temp++;
        if (to_string((*blockIt)["newAccount"]).find(publicKey) != std::string::npos)
        {
            lifeTime = temp;
            break;
        }
    }

    return lifeTime;
}
