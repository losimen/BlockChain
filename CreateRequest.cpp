//
// Created by Павло Коваль on 19.07.2022.
//

#include "CreateRequest.h"

json CreateRequest::createNewAccount() {
    KeyPair keyPair = account_.createNewAccount();

    requestData_["type"] = "newAccount";
    requestData_["account"] = keyPair.getPublicKeyStr();

    return requestData_;
}

json CreateRequest::createNewAccount(const KeyPair &keyPair) {
    account_.createNewAccount(keyPair);

    requestData_["type"] = "newAccount";
    requestData_["account"] = keyPair.getPublicKeyStr();

    return requestData_;
}

json CreateRequest::createNewPublicMessage(KeyPair &keyPair, const std::string &topicID, const std::string &messageContent) {
    if (Security::isKeyPairValid(keyPair))
        throw std::runtime_error("KeyPair is not valid");

    message_.createPublicMessage(topicID, messageContent);

    requestData_ = message_.getMessageData();
    requestData_["type"] = "newMessage";

    return requestData_;
}

json CreateRequest::createNewPrivateMessage(KeyPair &keyPair, const std::string &receiverID, const std::string &topicID, const std::string &messageContent) {
    if (Security::isKeyPairValid(keyPair))
        throw std::runtime_error("KeyPair is not valid");

    message_.createPrivateMessage(receiverID, topicID, messageContent);

    requestData_ = message_.getMessageData();
    requestData_["type"] = "newMessage";

    return requestData_;
}

json CreateRequest::createNewTopic(KeyPair &keyPair, const std::string &topicName, const std::string &topicDescription) {
    if (Security::isKeyPairValid(keyPair))
        throw std::runtime_error("KeyPair is not valid");

    topic_.createNewTopic(topicName, topicDescription);

    requestData_ = topic_.getTopicData();
    requestData_["type"] = "newTopic";

    return requestData_;
}
