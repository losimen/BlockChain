#include <iostream>

#include "Security.h"


int main() {
    KeyPair keyPair("new");
    keyPair.generateKeyPair();

    std::string msgToEncrypt = "Hello my name is Liam";
    std::string encryptedText = Security::encryptPublicMSG(keyPair, msgToEncrypt);
    std::string decryptedText = Security::decryptPrivateMSG(keyPair, encryptedText);

    std::cout << decryptedText << std::endl;

    return 0;
}
