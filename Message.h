//
// Created by Павло Коваль on 17.07.2022.
//

#ifndef BLOCKCHAIN_MESSAGE_H
#define BLOCKCHAIN_MESSAGE_H

#include <utility>

#include "Security.h"
#include "TimeWorker.h"

class Message {
private:
    json messageData;

    static RSA *convertPrivateKeyToRSA(const std::string &privateKey);
    static RSA *convertPublicKeyToRSA(const std::string &publicKey);

public:
    const json &getMessageData() const;

    Message createPublicMessage(const std::string &topicID, const std::string &messageContent);
    Message createPrivateMessage(const std::string &receiverID, const std::string &topicID, const std::string &messageContent);
};

#endif //BLOCKCHAIN_MESSAGE_H
