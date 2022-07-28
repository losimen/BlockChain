//
// Created by Павло Коваль on 19.07.2022.
//

#include "CreateRequest.h"

json CreateRequest::createNewAccount() {
    KeyPair keyPair = account_.createNewAccount();

    requestData_["type"] = "newAccount";
    requestData_["data"] = keyPair.getPublicKeyStr();

    return requestData_;
}

json CreateRequest::createNewAccount(const KeyPair &keyPair) {
    account_.createNewAccount(keyPair);

    requestData_["type"] = "newAccount";
    requestData_["data"] = keyPair.getPublicKeyStr();

    return requestData_;
}

json CreateRequest::createNewPublicMessage(KeyPair &keyPair, const std::string &topicID, const std::string &messageContent) {
    if (!Security::isKeyPairValid(keyPair))
        throw std::runtime_error("KeyPair is not valid");

    message_.createPublicMessage(keyPair.getPublicKeyStr(), topicID, messageContent);

    requestData_["type"] = "newMessage";
    requestData_["data"] = message_.getMessageData();

    return requestData_;
}

json CreateRequest::createNewPrivateMessage(KeyPair &keyPair, const std::string &receiverID, const std::string &topicID, const std::string &messageContent) {
    if (!Security::isKeyPairValid(keyPair))
        throw std::runtime_error("KeyPair is not valid");

    message_.createPrivateMessage(keyPair.getPublicKeyStr(), receiverID, topicID, messageContent);

    requestData_["type"] = "newMessage";
    requestData_["data"] = message_.getMessageData();

    return requestData_;
}

json CreateRequest::createNewTopic(KeyPair &keyPair, const std::string &topicName, const std::string &topicDescription, const std::string &topicID) {
    if (!Security::isKeyPairValid(keyPair))
        throw std::runtime_error("KeyPair is not valid");

    topic_.createNewTopic(keyPair.getPublicKeyStr(), topicName, topicDescription, topicID);

    requestData_["type"] = "newTopic";
    requestData_["data"] = topic_.getTopicData();

    return requestData_;
}
