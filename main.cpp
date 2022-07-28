#include <iostream>

#include "BlockChain.h"

int main()
{
    BlockChain blockChain;
    Block block(std::string(blockChain.getLastBlock().getCurrentHash()));

    CreateRequest createRequest;

    KeyPair keyPair_other("other");
    KeyPair keyPair("me");

    json listOfRequests;

    listOfRequests.push_back(createRequest.createNewTopic(keyPair, "topicName", "topicDescription", "topicID"));
    listOfRequests.push_back(createRequest.createNewTopic(keyPair, "topicName", "topicDescription"));
    listOfRequests.push_back(createRequest.createNewPublicMessage(keyPair, "Hello", "Hello world"));
    listOfRequests.push_back(createRequest.createNewPublicMessage(keyPair, "Good", "How are you?"));

    block.createNewBlock(listOfRequests);
    blockChain.validateNewBlock(block);

//    std::cout << block;

    return 0;
}
