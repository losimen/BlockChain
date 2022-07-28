#include <iostream>
#include <fstream>

#include "KeyPair.h"
#include "CreateRequest.h"


int main()
{
    CreateRequest createRequest;

    KeyPair keyPair_other("other");
    KeyPair keyPair("me");

    std::vector<json> listOfRequests;

    listOfRequests.push_back(createRequest.createNewTopic(keyPair, "topicName", "topicDescription", "topicID"));
    listOfRequests.push_back(createRequest.createNewTopic(keyPair, "topicName", "topicDescription"));
    listOfRequests.push_back(createRequest.createNewPublicMessage(keyPair, "Hello", "Hello world"));
    listOfRequests.push_back(createRequest.createNewPublicMessage(keyPair, "Good", "How are you?"));


    for (auto el: listOfRequests)
        std::cout << el.dump(4) << std::endl;

    return 0;
}
