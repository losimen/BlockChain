//
// Created by Павло Коваль on 21.07.2022.
//

#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H

#include "Block.h"

class BlockChain {
private:
    std::vector<Block> blockChain_;

public:
    void validateNewBlock(Block &newBlock);

};


#endif //BLOCKCHAIN_BLOCKCHAIN_H
