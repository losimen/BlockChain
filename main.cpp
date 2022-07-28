#include <iostream>
#include <fstream>

#include "Block.h"

int main()
{
    Block block("none");
    CreateRequest createRequest;

    KeyPair keyPair_other("other");
    KeyPair keyPair("me");

    json listOfRequests;

    listOfRequests.push_back(createRequest.createNewTopic(keyPair, "topicName", "topicDescription", "topicID"));
    listOfRequests.push_back(createRequest.createNewTopic(keyPair, "topicName", "topicDescription"));
    listOfRequests.push_back(createRequest.createNewPublicMessage(keyPair, "Hello", "Hello world"));
    listOfRequests.push_back(createRequest.createNewPublicMessage(keyPair, "Good", "How are you?"));

    block.createNewBlock(listOfRequests);
    std::cout << block;

    return 0;
}
