//
// Created by Павло Коваль on 17.07.2022.
//

#ifndef BLOCKCHAIN_MESSAGE_H
#define BLOCKCHAIN_MESSAGE_H

#include <utility>

#include "Security.h"

class Message {
private:
    const static std::string blockType_;

    std::string messageId_;
    std::string messageContent_;

    std::string createdAt_;
public:
    Message(std::string messageId, std::string messageContent, std::string createdAt):
            messageId_(std::move(messageId)),
            messageContent_(std::move(messageContent)),
            createdAt_(std::move(createdAt))
            {}

    explicit Message(std::string messageId):
            messageId_(std::move(messageId))
            {}

    void postPublicMessage();
    void postPrivateMessage();
};

#endif //BLOCKCHAIN_MESSAGE_H
