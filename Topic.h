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
    std::string topicID_;
    std::string topicName_;
    std::string topicDescription_;
    std::vector<Message> topicMessages_;
    std::string createdAt_;

public:
    void createNewTopic(const std::string &topicName, const std::string &topicDescription);

    const std::string &getTopicID() const;
    const std::vector<Message> &getTopicMessages() const;
    const std::string &getTopicName() const;
    const std::string &getCreatedAt() const;
    const std::string &getTopicDescription() const;
};


#endif //BLOCKCHAIN_TOPIC_H
