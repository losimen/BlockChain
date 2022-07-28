#include <iostream>

#include "BlockChain.h"

int main()
{
    BlockChain blockChain;
//    Block block(std::string(blockChain.getLastBlock().getCurrentHash()));

//    CreateRequest createRequest;

//    KeyPair keyPair_other("other");
//    KeyPair keyPair("me");

//    json listOfRequests;

//    listOfRequests.push_back(createRequest.createNewAccount(keyPair));
//    listOfRequests.push_back(createRequest.createNewTopic(keyPair, "topicName", "topicDescription", "topicID"));
//    listOfRequests.push_back(createRequest.createNewTopic(keyPair, "topicName", "topicDescription"));
//    listOfRequests.push_back(createRequest.createNewPublicMessage(keyPair, "Hello", "Hello world"));
//    listOfRequests.push_back(createRequest.createNewPublicMessage(keyPair, "Good", "How are you?"));

//    block.createNewBlock(listOfRequests);
//    blockChain.validateNewBlock(block);

    auto el = blockChain.getUserReputation("MIIBCgKCAQEAkAzYRWVSm3T2zADxCunjcGi1TGyiip7uVmuhgwKOwEwn+DnNb6mY+dA+6aV8wSmkL6B5eeB4M4qvz0C6L2dYiJqk09Hla2h7NrDAi1RNKTmuoEtqrODLtmmhhA7PWGoGQPhLMjNj4ZRs1F/1gNVMo/cL6svipAoqDwoo4W5S0jsyqO1VpC910xiip1IPeJSf24GJ5Yn3vGnXvh9LMft64NfHwfTgXApHxta1/WaVBs0TkWGdDMZ6rnEidnNQj+3yegXDdOH5zf5l8Dedvzy1EU+JH0BCtMrEKUXWjg6IwopQ9XLGRA/IWwpYxFr8O7ZkdsfH1y0AzP+wsyLYO6TMXwIDAQ");
    std::cout << el << std::endl;

    return 0;
}
