//
// Created by Павло Коваль on 17.07.2022.
//

#ifndef BLOCKCHAIN_MESSAGE_H
#define BLOCKCHAIN_MESSAGE_H

#include <utility>

#include "Security.h"

class Message {
private:
    std::string messageID_;
    std::string topicID_;
    std::string messageContent_;
    std::string createdAt_;

public:
    Message createPublicMessage(const std::string &topicID, const std::string &messageContent);
    Message createPrivateMessage(const std::string &receiverID, const std::string &topicID, const std::string &messageContent);

    const std::string &getMessageID() const;
    const std::string &getMessageContent() const;
    const std::string &getCreatedAt() const;
    const std::string &getTopicId() const;
};

#endif //BLOCKCHAIN_MESSAGE_H
