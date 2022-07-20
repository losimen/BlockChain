//
// Created by Павло Коваль on 20.07.2022.
//

#ifndef BLOCKCHAIN_REQUESTDATA_H
#define BLOCKCHAIN_REQUESTDATA_H


#include <string>
#include <vector>

struct RequestData {
    std::string type;
    std::string dataSingular;
    std::vector<std::string> dataPlural;
};



#endif //BLOCKCHAIN_REQUESTDATA_H
