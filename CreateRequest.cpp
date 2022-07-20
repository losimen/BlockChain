//
// Created by Павло Коваль on 19.07.2022.
//

#include "CreateRequest.h"

RequestData CreateRequest::createNewAccount() {
    KeyPair keyPair = account_.createNewAccount();

    requestData_["type"] = "newAccount";
    requestData_["data"] = keyPair.getPublicKeyStr();

    return requestData_;
}

RequestData CreateRequest::createNewAccount(const KeyPair &keyPair) {
    account_.createNewAccount(keyPair);

    requestData_["type"] = "newAccount";
    requestData_["data"] = keyPair.getPublicKeyStr();

    return requestData_;
}

RequestData CreateRequest::createNewPublicMessage(const std::string &topicID, const std::string &messageContent) {
    message_.createPublicMessage(topicID, messageContent);

    requestData_["type"] = "newMessage";
    requestData_["data"] = message_.getMessageContent();

    return requestData_;
}

RequestData CreateRequest::createNewPrivateMessage(const std::string &topicID, const std::string &messageContent) {
    message_.createPrivateMessage(topicID, messageContent);

    requestData_["type"] = "newMessage";
    requestData_["data"] = message_.getMessageContent();

    return requestData_;
}



