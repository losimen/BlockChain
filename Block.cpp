//
// Created by Павло Коваль on 19.07.2022.
//

#include "Block.h"


Block::Block(std::string prevBlockHash) :
        prevBlockHash_(std::move(prevBlockHash))
{
    currentBlockHash_ = "none";

    blockData["newAccount"] = std::vector<std::string>();
    blockData["newMessage"] = std::vector<std::string>();
    blockData["newTopic"] = std::vector<std::string>();
};


Block Block::createNewBlock(const std::vector<RequestData> &listOfRequests) {
    std::string currentHash = getBlockHash_();

    if (listOfRequests.empty()) {
        throw std::runtime_error("List of requests is empty");
    }

    for (auto request: listOfRequests) {
        if (request["type"] == "newAccount") {
            blockData["newAccount"].push_back(request["data"]);
        } else if (request["type"] == "newMessage") {
            blockData["newMessage"].push_back(request["data"]);
        } else if (request["type"] == "newTopic") {
            blockData["newTopic"].push_back(request["data"]);
        }
        else {
            throw std::runtime_error("Unknown request type");
        }
    }

    return *this;
}

std::string Block::getRandomString_() {
    const int length = 100;
    std::string result;
    std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789/][';.,=+-_)(*&^%$#@!~`";

    // get random number C++11
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, int(chars.length()) - 1);

    for (int i = 0; i < length; i++) {
        result += chars[dis(gen)];
    }

    return result;
}


std::string Block::getBlockHash_() {
    std::string blockHash = Security::SHA256generator(getRandomString_());

    while (blockHash.substr(0, 15) == std::string(30, '0'))
        blockHash = Security::SHA256generator(getRandomString_());

    return blockHash;
}
