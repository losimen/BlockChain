//
// Created by Павло Коваль on 19.07.2022.
//

#include "CreateRequest.h"

RequestData CreateRequest::createNewAccount() {
    KeyPair keyPair = account_.createNewAccount();

    requestData_.type = "newAccount";
    requestData_.dataSingular = keyPair.getPublicKeyStr();

    return requestData_;
}

RequestData CreateRequest::createNewAccount(const KeyPair &keyPair) {
    account_.createNewAccount(keyPair);

    requestData_.type = "newAccount";
    requestData_.dataSingular = keyPair.getPublicKeyStr();

    return requestData_;
}

RequestData CreateRequest::createNewPublicMessage(const std::string &topicID, const std::string &messageContent) {
    message_.createPublicMessage(topicID, messageContent);

    requestData_.type = "newMessage";

    requestData_.dataPlural.push_back(message_.getMessageID());
    requestData_.dataPlural.push_back(message_.getTopicId());
    requestData_.dataPlural.push_back(message_.getMessageContent());
    requestData_.dataPlural.push_back(message_.getCreatedAt());

    return requestData_;
}

RequestData CreateRequest::createNewPrivateMessage(const std::string &receiverID, const std::string &topicID, const std::string &messageContent) {
    message_.createPrivateMessage(receiverID, topicID, messageContent);

    requestData_.type = "newMessage";

    requestData_.dataPlural.push_back(message_.getMessageID());
    requestData_.dataPlural.push_back(message_.getTopicId());
    requestData_.dataPlural.push_back(message_.getMessageContent());
    requestData_.dataPlural.push_back(message_.getCreatedAt());

    return requestData_;
}

RequestData CreateRequest::createNewTopic(const std::string &topicName, const std::string &topicDescription) {
    topic_.createNewTopic(topicName, topicDescription);

    requestData_.type = "newTopic";

    requestData_.dataPlural.push_back(topic_.getTopicID());
    requestData_.dataPlural.push_back(topic_.getTopicName());
    requestData_.dataPlural.push_back(topic_.getTopicDescription());
    requestData_.dataPlural.push_back(topic_.getCreatedAt());

    return requestData_;
}
