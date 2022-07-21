//
// Created by Павло Коваль on 17.07.2022.
//

#include "Message.h"

Message Message::createPublicMessage(const std::string &topicID, const std::string &messageContent) {
    RSA* rsa = convertPublicKeyToRSA(topicID);
    std::string encryptedMessage = Security::encryptPublicMSG(rsa, messageContent);

//    messageData["creator"] = account_.getPublicKeyStr();
    messageData["topicID"] = topicID;
    messageData["messageID"] = Security::SHA256generatorRandom();
    messageData["messageContent"] = encryptedMessage;
    messageData["createdAt"] = TimeWorker::getCurrentTime();

    return *this;
}

Message Message::createPrivateMessage(const std::string &receiverID, const std::string &topicID, const std::string &messageContent) {
    RSA* rsa = convertPrivateKeyToRSA(receiverID);

    std::string encryptedMessage = Security::encryptPublicMSG(rsa, messageContent);

    //    messageData["creator"] = account_.getPublicKeyStr();
    messageData["topicID"] = topicID;
    messageData["messageID"] = Security::SHA256generatorRandom();
    messageData["messageContent"] = encryptedMessage;
    messageData["createdAt"] = TimeWorker::getCurrentTime();

    return *this;
}

const json &Message::getMessageData() const {
    return messageData;
}

RSA *Message::convertPrivateKeyToRSA(const std::string &privateKey) {
    char secret[] = "loh6";
    BIO* bio = BIO_new(BIO_s_mem());

    BIO_write(bio, (void*)privateKey.c_str(), int(privateKey.length()));
    EVP_PKEY* evp_key = PEM_read_bio_PUBKEY(bio, nullptr, nullptr, nullptr);
    PEM_read_bio_PrivateKey( bio, nullptr, nullptr, secret);

    return EVP_PKEY_get1_RSA(evp_key);
}

RSA *Message::convertPublicKeyToRSA(const std::string &publicKey) {
    BIO* bio = BIO_new(BIO_s_mem());

    BIO_write(bio, (void*)publicKey.c_str(), int(publicKey.length()));
    EVP_PKEY* evp_key = PEM_read_bio_PUBKEY(bio, nullptr, nullptr, nullptr);
    return EVP_PKEY_get1_RSA(evp_key);
}

