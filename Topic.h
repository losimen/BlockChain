//
// Created by Павло Коваль on 17.07.2022.
//

#ifndef BLOCKCHAIN_TOPIC_H
#define BLOCKCHAIN_TOPIC_H

#include "Security.h"
#include "Message.h"

#include <vector>

class Topic {
private:
    const static std::string blockType;

    std::string topicId_;
    std::string topicName_;
    std::string topicDescription_;
    std::vector<Message> topicMessages_;

    std::string createdAt_;
public:
    explicit Topic(std::string topicId):
        topicId_(std::move(topicId))
        {}

    void createNewTopic(const std::string &topicName, const std::string &topicDescription);

    void addNewPublicMessage(Message &messageToAdd, const std::string &privateKeyFileName);
    void addNewPrivateMessage(Message &messageToAdd, const std::string &publicKeyFileName);

    const std::vector<Message> &getTopicMessages() const;
    const std::string &getTopicName() const;
    const std::string &getCreatedAt() const;
    const std::string &getTopicDescription() const;

    void gatherMessages();
};


#endif //BLOCKCHAIN_TOPIC_H
