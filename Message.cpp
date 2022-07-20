//
// Created by Павло Коваль on 17.07.2022.
//

#include "Message.h"

Message Message::createPublicMessage(const std::string &topicID, const std::string &messageContent) {
    BIO* bio = BIO_new(BIO_s_mem());

    BIO_write(bio, (void*)messageContent.c_str(), int(messageContent.length()));
    EVP_PKEY* evp_key = PEM_read_bio_PUBKEY(bio, NULL, NULL, NULL);
    RSA* rsa = EVP_PKEY_get1_RSA(evp_key);

    std::string encryptedMessage = Security::encryptPublicMSG(rsa, messageContent);

    time_t now = time(nullptr);
    char* dt = ctime(&now);

    messageId_ = Security::SHA256generatorRandom();
    messageContent_ = encryptedMessage;
    createdAt_ = dt;

    return *this;
}

Message Message::createPrivateMessage(const std::string &receiverID, const std::string &messageContent) {
    char secret[] = "loh6";
    BIO* bio = BIO_new(BIO_s_mem());

    BIO_write(bio, (void*)messageContent.c_str(), int(messageContent.length()));
    EVP_PKEY* evp_key = PEM_read_bio_PUBKEY(bio, NULL, NULL, NULL);
    PEM_read_bio_PrivateKey( bio, nullptr, nullptr, secret);

    RSA* rsa = EVP_PKEY_get1_RSA(evp_key);

    std::string encryptedMessage = Security::encryptPublicMSG(rsa, messageContent);

    time_t now = time(nullptr);
    char* dt = ctime(&now);

    messageId_ = Security::SHA256generatorRandom();
    messageContent_ = encryptedMessage;
    createdAt_ = dt;

    return *this;
}

const std::string &Message::getMessageId() const {
    return messageId_;
}

const std::string &Message::getMessageContent() const {
    return messageContent_;
}

const std::string &Message::getCreatedAt() const {
    return createdAt_;
}
