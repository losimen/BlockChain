//
// Created by Павло Коваль on 17.07.2022.
//

#include "Topic.h"

const std::string Topic::blockType = "topic";

const std::string &Topic::getTopicName() const {
    return topicName_;
}

const std::string &Topic::getTopicDescription() const {
    return topicDescription_;
}

const std::vector<Message> &Topic::getTopicMessages() const {
    return topicMessages_;
}

const std::string &Topic::getCreatedAt() const {
    return createdAt_;
}

void Topic::createNewTopic(const std::string &topicName, const std::string &topicDescription) {
    topicId_ = Security::SHA256generatorRandom();
    topicName_ = topicName;
    topicDescription_ = topicDescription;
}
