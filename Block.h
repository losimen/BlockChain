//
// Created by Павло Коваль on 19.07.2022.
//

#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include <ostream>
#include "CreateRequest.h"


class Block {
private:
    static const int SECURITY_LEVEL;

    json blockData;

    std::string currentBlockHash_;
    std::string prevBlockHash_;

    static std::string generateBlockHash_();
public:

    Block() = delete;
    explicit Block(std::string prevBlockHash);

    Block createNewBlock(const std::vector<json> &listOfRequests);

    const std::string &getCurrentBlockHash() const;
    const std::string &getPrevBlockHash() const;

    friend std::ostream &operator<<(std::ostream &os, const Block &block);
};


#endif //BLOCKCHAIN_BLOCK_H
