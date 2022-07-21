//
// Created by Павло Коваль on 17.07.2022.
//

#include "Message.h"

void Message::createPublicMessage(const std::string &topicID, const std::string &messageContent) {
    messageData_ = {
         {"topicID", topicID},
         {"messageID", Security::SHA256generatorRandom()},
         {"messageContent", messageContent},
         {"createdAt", TimeWorker::getCurrentTime()}
    };
}

void Message::createPrivateMessage(const std::string &receiverID, const std::string &topicID, const std::string &messageContent) {
    RSA* rsa = convertPrivateKeyToRSA(receiverID);
    std::string encryptedMsg = Security::encryptPublicMSG(rsa, messageContent);

    messageData_ = {
         {"topicID", topicID},
         {"messageID", Security::SHA256generatorRandom()},
         {"messageContent", base64_encode(reinterpret_cast<unsigned char*>(const_cast<char*>(encryptedMsg.c_str())), encryptedMsg.size())},
         {"createdAt", TimeWorker::getCurrentTime()}
    };
}

const json &Message::getMessageData() const {
    return messageData_;
}

RSA *Message::convertPrivateKeyToRSA(const std::string &privateKey) {
    char secret[] = "loh6";
    BIO* bio = BIO_new(BIO_s_mem());

    BIO_write(bio, (void*)privateKey.c_str(), int(privateKey.length()));
    EVP_PKEY* evp_key = PEM_read_bio_PUBKEY(bio, nullptr, nullptr, nullptr);
    PEM_read_bio_PrivateKey( bio, nullptr, nullptr, secret);

    return EVP_PKEY_get1_RSA(evp_key);
}
