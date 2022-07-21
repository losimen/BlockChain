cmake_minimum_required(VERSION 3.22)
project(BlockChain)

set(CMAKE_CXX_STANDARD 14)

set(OPENSSL_INCLUDE_DIR /opt/homebrew/opt/openssl@3/include)
set(OPENSSL_LIBRARIES /opt/homebrew/opt/openssl@3/lib)

find_package(OpenSSL REQUIRED)
find_package(ZLIB)
find_package(nlohmann_json 3.2.0 REQUIRED)

add_executable(BlockChain
        main.cpp
        KeyPair.cpp KeyPair.h
        Account.cpp Account.h
        base64.cpp base64.h
        Security.cpp Security.h
        Message.cpp Message.h
        Topic.cpp Topic.h
        CreateRequest.cpp CreateRequest.h
        Block.cpp Block.h
        TimeWorker.cpp TimeWorker.h
        BlockChain.cpp BlockChain.h)

target_link_libraries(BlockChain OpenSSL::SSL OpenSSL::Crypto ZLIB::ZLIB nlohmann_json::nlohmann_json)
