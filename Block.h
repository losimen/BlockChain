//
// Created by Павло Коваль on 19.07.2022.
//

#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include "CreateRequest.h"

class Block {
private:
    std::string currentBlockHash_;
    std::string prevBlockHash_;

    std::vector<RequestData> listOfRequests_;

public:
    Block createNewBlock(const std::vector<RequestData> &listOfRequests, const std::string &prevBlockHash);

};


#endif //BLOCKCHAIN_BLOCK_H
