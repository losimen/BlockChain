//
// Created by Павло Коваль on 19.07.2022.
//

#include "Block.h"

#include <utility>

const int Block::SECURITY_LEVEL = 3;

Block::Block(const std::string& prevBlockHash)
{
    blockData["newAccount"] = json::array();
    blockData["newMessage"] = json::array();
    blockData["newTopic"] = json::array();
    blockData["prevBlockHash"] = prevBlockHash;
    blockData["currentBlockHash"] = "";
};

Block::Block(json blockData) : blockData(std::move(blockData))
{}


Block Block::createNewBlock(const json &listOfRequests) {
    if (listOfRequests.empty())
        throw std::runtime_error("List of requests is empty");

    std::string currentBlockHash = generateBlockHash_();
    blockData["currentBlockHash"] = currentBlockHash;

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


std::string Block::generateBlockHash_() {
    std::string blockHash = Security::SHA256generatorRandom();

    while (blockHash.substr(0, SECURITY_LEVEL) != std::string(SECURITY_LEVEL, '0'))
        blockHash = Security::SHA256generatorRandom();

    return blockHash;
}

std::ostream &operator<<(std::ostream &os, const Block &block) {
    os << block.blockData.dump(4);
    return os;
}

const json &Block::getBlockData() const {
    return blockData;
}

const json &Block::getCurrentHash() const {
    return blockData["currentBlockHash"];
}

const json &Block::getPrevBlockHash() const {
    return blockData["prevBlockHash"];
}