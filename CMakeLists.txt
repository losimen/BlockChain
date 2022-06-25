cmake_minimum_required(VERSION 3.22)
project(BlockChain)

set(CMAKE_CXX_STANDARD 14)

set(OPENSSL_INCLUDE_DIR /opt/homebrew/opt/openssl@3/include)
set(OPENSSL_LIBRARIES /opt/homebrew/opt/openssl@3/lib)

find_package(OpenSSL REQUIRED)
find_package(ZLIB)

add_executable(BlockChain main.cpp)
target_link_libraries(BlockChain OpenSSL::SSL OpenSSL::Crypto ZLIB::ZLIB)
