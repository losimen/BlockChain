//
// Created by Павло Коваль on 17.07.2022.
//

#include <iostream>
#include "Topic.h"

void Topic::createNewTopic(const std::string &creatorID, const std::string &topicName, const std::string &topicDescription, const std::string &topicID) {
    topicData_ = {
        {"topicID", topicID},
        {"creatorID", creatorID},
        {"topicName", topicName},
        {"topicDescription", topicDescription},
        {"createdAt", TimeWorker::getCurrentTime()}
    };
}

const json &Topic::getTopicData() const {
    return topicData_;
}
