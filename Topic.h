//
// Created by Павло Коваль on 17.07.2022.
//

#ifndef BLOCKCHAIN_TOPIC_H
#define BLOCKCHAIN_TOPIC_H

#include "Security.h"
#include "Message.h"
#include "TimeWorker.h"

#include <vector>

class Topic {
private:
    json topicData_;

public:
    void createNewTopic(const std::string &creatorID, const std::string &topicName, const std::string &topicDescription);
    const json &getTopicData() const;
};


#endif //BLOCKCHAIN_TOPIC_H
