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
    // request types:
    // -0 newTopic
    // -1 newMessage
    // -2 newAccount

    RequestData requestData_;

    Account account_;
    Topic topic_;
    Message message_;

public:
    RequestData createNewAccount();
    RequestData createNewAccount(const KeyPair &keyPair);

    RequestData createNewPublicMessage(const std::string &topicID, const std::string &messageContent);
    RequestData createNewPrivateMessage(const std::string &topicID, const std::string &messageContent);

    RequestData createNewTopic(const std::string &topicName, const std::string &topicDescription);
};


#endif //BLOCKCHAIN_CREATEREQUEST_H
