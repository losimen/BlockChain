//
// Created by Павло Коваль on 19.07.2022.
//

#include "Block.h"

const int Block::SECURITY_LEVEL = 3;

Block::Block(std::string prevBlockHash) :
        prevBlockHash_(std::move(prevBlockHash))
{
    currentBlockHash_ = "none";

    blockData["newAccount"] = json::array();
    blockData["newMessage"] = json::array();
    blockData["newTopic"] = json::array();
};


Block Block::createNewBlock(const std::vector<json> &listOfRequests) {
    currentBlockHash_ = generateBlockHash_();

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

    blockData["prevBlockHash"] = prevBlockHash_;
    blockData["currentBlockHash"] = currentBlockHash_;

    return *this;
}


std::string Block::generateBlockHash_() {
    std::string blockHash = Security::SHA256generatorRandom();

    while (blockHash.substr(0, SECURITY_LEVEL) != std::string(SECURITY_LEVEL, '0'))
        blockHash = Security::SHA256generatorRandom();

    return blockHash;
}

const std::string &Block::getCurrentBlockHash() const {
    return currentBlockHash_;
}

const std::string &Block::getPrevBlockHash() const {
    return prevBlockHash_;
}

std::ostream &operator<<(std::ostream &os, const Block &block) {
    os << block.blockData.dump(4);
    return os;
}
