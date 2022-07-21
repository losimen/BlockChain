//
// Created by Павло Коваль on 17.07.2022.
//

#include <iostream>
#include "Topic.h"

void Topic::createNewTopic(const std::string &topicName, const std::string &topicDescription) {
//    topicData["creator"] = account_.getPublicKeyStr();

    topicData["topicName"] = topicName;
    topicData["topicDescription"] = topicDescription;
    topicData["topicID"] = Security::SHA256generatorRandom();
    topicData["createdAt"] = TimeWorker::getCurrentTime();
}

const json &Topic::getTopicData() const {
    return topicData;
}
