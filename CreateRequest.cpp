//
// Created by Павло Коваль on 19.07.2022.
//

#include "CreateRequest.h"

RequestData CreateRequest::createNewAccount() {
    KeyPair keyPair = account_.createNewAccount();

    requestData_["fieldName"] = "newAccount";
    requestData_["fieldData"] = keyPair.getPublicKeyStr();

    return requestData_;
}

RequestData CreateRequest::createNewAccount(const KeyPair &keyPair) {
    account_.createNewAccount(keyPair);

    requestData_["fieldName"] = "newAccount";
    requestData_["fieldData"] = keyPair.getPublicKeyStr();

    return requestData_;
}


