//
// Created by Павло Коваль on 21.07.2022.
//

#include "BlockChain.h"

const std::string BlockChain::dbFileName_ = "BlockChain.json";

BlockChain::BlockChain() {
    if (!isFileExists_(dbFileName_))
    {
        blockChain_.push_back(Block(std::string("")).getBlockData());
        return;
    }

    std::ifstream f(dbFileName_);
    blockChain_ = json::parse(f);
    f.close();
}

void BlockChain::validateNewBlock(Block &newBlock) {
    if (newBlock.getPrevBlockHash() != getLastBlock().getCurrentHash() || newBlock.getCurrentHash() == getLastBlock().getCurrentHash())
        throw std::runtime_error("Invalid previous block hash");

    std::ofstream myfile;
    myfile.open (dbFileName_);
    blockChain_.push_back(newBlock.getBlockData());

    if (myfile.is_open())
    {
        myfile << blockChain_.dump(4);
        myfile.close();
    }
    else
        std::cout << "Unable to open file";
}

bool BlockChain::isFileExists_(const std::string &fileName) {
    std::ifstream f(fileName.c_str());
    return f.good();
}

Block BlockChain::getLastBlock() {
    json lastBlock = blockChain_.back();
    return Block(lastBlock);
}

double BlockChain::getUserReputation(const std::string &publicKey) {
    Account account;

    return account.getReputation(publicKey, blockChain_);
}
