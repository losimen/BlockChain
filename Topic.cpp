//
// Created by Павло Коваль on 17.07.2022.
//

#include <iostream>
#include "Topic.h"

void Topic::createNewTopic(const std::string &topicName, const std::string &topicDescription) {
    topicData_ = {
        {"topicID", Security::SHA256generatorRandom()},
        {"topicName", topicName},
        {"topicDescription", topicDescription},
        {"createdAt", TimeWorker::getCurrentTime()}
    };
}

const json &Topic::getTopicData() const {
    return topicData_;
}
