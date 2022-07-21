//
// Created by Павло Коваль on 19.07.2022.
//

#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include "CreateRequest.h"


class Block {
private:
    json blockData;

    std::string currentBlockHash_;
    std::string prevBlockHash_;

    static std::string getBlockHash_();

public:
    Block() = delete;
    explicit Block(std::string prevBlockHash);

    Block createNewBlock(const std::vector<json> &listOfRequests);
};


#endif //BLOCKCHAIN_BLOCK_H
