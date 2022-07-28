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

    static std::string generateBlockHash_();
public:
    Block() = delete;

    explicit Block(const std::string& prevBlockHash);
    explicit Block(json blockData);

    Block createNewBlock(const json &listOfRequests);

    const json &getBlockData() const;
    const json &getCurrentHash() const;
    const json &getPrevBlockHash() const;

    friend std::ostream &operator<<(std::ostream &os, const Block &block);
};


#endif //BLOCKCHAIN_BLOCK_H
