//
// Created by Павло Коваль on 18.07.2022.
//

#ifndef BLOCKCHAIN_SECURITY_H
#define BLOCKCHAIN_SECURITY_H

#include "KeyPair.h"

class Security {
public:
    // USAGE:
    // --VISIBLE FOR CURRENT USER WHICH PUBLIC KEY YOU HAVE USED:
    // encryptPublic -> decryptPrivate
    //
    // --VISIBLE FOR ALL:
    // encryptPrivate -> decrypt public

    static std::string encryptPublicMSG(KeyPair &keyPair, const std::string &toEncrypt);
    static std::string encryptPrivateMSG(KeyPair &keyPair, const std::string &toEncrypt);

    static std::string decryptPrivateMSG(KeyPair &keyPair, const std::string &toDecrpyt);
    static std::string decryptPublicMSG(KeyPair &keyPair, const std::string &toDecrpyt);
};


#endif //BLOCKCHAIN_SECURITY_H
