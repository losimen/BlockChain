//
// Created by Павло Коваль on 21.07.2022.
//

#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H

#include "Block.h"

#include <fstream>

class BlockChain {
private:
    json blockChain_;
    static const std::string dbFileName_;

    static bool isFileExists_(const std::string &fileName);

public:
    BlockChain();

    void validateNewBlock(Block &newBlock);
    double getUserReputation(const std::string &publicKey);

    Block getLastBlock();

};


#endif //BLOCKCHAIN_BLOCKCHAIN_H
