//
// Created by Павло Коваль on 19.07.2022.
//

#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include "CreateRequest.h"
#include <map>

typedef std::map<std::string, std::vector<std::vector<std::string>>> BlockData;

class Block {
private:
    BlockData blockData;

    std::string currentBlockHash_;
    std::string prevBlockHash_;

    static std::string getBlockHash_();

public:
    explicit Block(std::string prevBlockHash);

    Block createNewBlock(const std::vector<RequestData> &listOfRequests);

};


#endif //BLOCKCHAIN_BLOCK_H
