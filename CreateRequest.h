//
// Created by Павло Коваль on 19.07.2022.
//

#ifndef BLOCKCHAIN_CREATEREQUEST_H
#define BLOCKCHAIN_CREATEREQUEST_H

#include "Topic.h"
#include "Account.h"

class CreateRequest {
private:
    // request types:
    // -0 newTopic
    // -1 newMessage
    // -2 newAccount

    json requestData_;

    Account account_;
    Topic topic_;
    Message message_;
public:
    json createNewAccount();
    json createNewAccount(const KeyPair &keyPair);

    json createNewPublicMessage(KeyPair &keyPair, const std::string &topicID, const std::string &messageContent);
    json createNewPrivateMessage(KeyPair &keyPair, const std::string &receiverID, const std::string &topicID, const std::string &messageContent);

    json createNewTopic(KeyPair &keyPair, const std::string &topicName, const std::string &topicDescription, const std::string &topicID = Security::SHA256generatorRandom());
};


#endif //BLOCKCHAIN_CREATEREQUEST_H
