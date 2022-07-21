//
// Created by Павло Коваль on 19.07.2022.
//

#include "Block.h"


Block::Block(std::string prevBlockHash) :
        prevBlockHash_(std::move(prevBlockHash))
{
    currentBlockHash_ = "none";

    blockData["newAccount"] = json::array();
    blockData["newMessage"] = json::array();
    blockData["newTopic"] = json::array();
};


Block Block::createNewBlock(const std::vector<json> &listOfRequests) {
    std::string currentHash = getBlockHash_();

    if (listOfRequests.empty())
        throw std::runtime_error("List of requests is empty");

    for (auto request: listOfRequests) {
        if (request["type"] == "newAccount")
            blockData["newAccount"].push_back(request["data"]);
        else if (request["type"] == "newMessage")
            blockData["newMessage"].push_back(request["data"]);
        else if (request["type"] == "newTopic")
            blockData["newTopic"].push_back(request["data"]);
        else
            throw std::runtime_error("Unknown request type");
    }

    return *this;
}


std::string Block::getBlockHash_() {
    std::string blockHash = Security::SHA256generatorRandom();

    while (blockHash.substr(0, 15) == std::string(30, '0'))
        blockHash = Security::SHA256generatorRandom();

    return blockHash;
}
