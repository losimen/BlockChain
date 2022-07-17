//
// Created by Павло Коваль on 17.07.2022.
//

#ifndef BLOCKCHAIN_BASE64_H
#define BLOCKCHAIN_BASE64_H

#ifndef _BASE64_H_
#define _BASE64_H_

#include <vector>
#include <string>
typedef unsigned char BYTE;

std::string base64_encode(BYTE const* buf, unsigned int bufLen);
std::vector<BYTE> base64_decode(std::string const&);

#endif

#endif //BLOCKCHAIN_BASE64_H
