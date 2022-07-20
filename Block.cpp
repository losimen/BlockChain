//
// Created by Павло Коваль on 19.07.2022.
//

#include "Block.h"


Block::Block(std::string prevBlockHash) :
        prevBlockHash_(std::move(prevBlockHash))
{
    currentBlockHash_ = "none";

//    blockData["newAccount"] = std::vector<std::string>();
//    blockData["newMessage"] = std::vector<std::string>();
//    blockData["newTopic"] = std::vector<std::string>();
};


Block Block::createNewBlock(const std::vector<RequestData> &listOfRequests) {
    std::string currentHash = getBlockHash_();

    if (listOfRequests.empty())
        throw std::runtime_error("List of requests is empty");


    for (auto request: listOfRequests) {
//        if (request["type"] == "newAccount") {
//            blockData["newAccount"].push_back(std::vector<std::string>{request["data"]});
//        } else if (request["type"] == "newMessage") {
//            std::vector<std::string> tempResult;
//
//            for (auto data: request["data"])
//                tempResult.push_back(data[]);
//
//            blockData["newAccount"].push_back(tempResult);
//        } else if (request["type"] == "newTopic") {
//            blockData["newAccount"].push_back(std::vector<std::string>{request["data"]});
//        }
//        else {
//            throw std::runtime_error("Unknown request type");
//        }
    }

    return *this;
}


std::string Block::getBlockHash_() {
    std::string blockHash = Security::SHA256generatorRandom();

    while (blockHash.substr(0, 15) == std::string(30, '0'))
        blockHash = Security::SHA256generatorRandom();

    return blockHash;
}
