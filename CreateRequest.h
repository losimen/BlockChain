//
// Created by Павло Коваль on 19.07.2022.
//

#ifndef BLOCKCHAIN_CREATEREQUEST_H
#define BLOCKCHAIN_CREATEREQUEST_H

#include "Topic.h"
#include "Account.h"

#include <map>

typedef std::map<std::string, std::string> RequestData;


class CreateRequest {
private:
    RequestData requestData_;

    Account account_;
    Topic topic_;
    Message message_;

public:
    RequestData createNewAccount();
    RequestData createNewAccount(const KeyPair &keyPair);


};


#endif //BLOCKCHAIN_CREATEREQUEST_H
