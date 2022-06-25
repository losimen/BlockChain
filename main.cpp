#include "KeyPair.h"

#include <vector>
#include <sstream>
#include <iostream>

std::string GetHex(std::vector<unsigned char> v)
{
    std::stringstream ss;
    for(size_t i=0;i<v.size();++i)
    {
        char c1[3]={};
        sprintf(c1,"%02x",v[i]);
        ss<<c1;
    }
    return ss.str();
}


std::vector<unsigned char> envelope_seal(EVP_PKEY **pub_key, unsigned char *plaintext, int plaintext_len,
                                    unsigned char **encrypted_key, int *encrypted_key_len, unsigned char *iv)
{
    EVP_CIPHER_CTX *ctx;
    int len;

    ctx = EVP_CIPHER_CTX_new();
    EVP_SealInit(ctx, EVP_aes_256_cbc(), encrypted_key,encrypted_key_len, iv, pub_key, 1);

    int blocksize=EVP_CIPHER_CTX_block_size(ctx);

    std::vector<unsigned char> cyphered(plaintext_len+blocksize-1);
    len=cyphered.size();
    EVP_SealUpdate(ctx, &cyphered[0], &len, plaintext, plaintext_len);

    EVP_SealFinal(ctx, &cyphered[0] + len, &len);

    return cyphered;
}


std::vector<unsigned char> envelope_open(EVP_PKEY *priv_key, unsigned char *ciphertext, int ciphertext_len,unsigned char *encrypted_key, int encrypted_key_len, unsigned char *iv)
{

    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;

    ctx = EVP_CIPHER_CTX_new();

    EVP_OpenInit(ctx, EVP_aes_256_cbc(), encrypted_key,encrypted_key_len, iv, priv_key);

    std::vector<unsigned char> plaintext(ciphertext_len);
    EVP_OpenUpdate(ctx, &plaintext[0], &len, ciphertext, ciphertext_len);
    plaintext_len = len;


    EVP_OpenFinal(ctx, &plaintext[0] + len, &len);
    plaintext_len += len;

    return plaintext;
}


std::vector<unsigned char> GetBinary(std::string s)
{
    std::vector<unsigned char> b;

    for(size_t i=0;i<s.size();i=i+2)
    {
        unsigned int c,c1;
        char str[2] ={s.c_str()[i],  0};sscanf(str,"%02x",&c);
        char str1[2]={s.c_str()[i+1],0};sscanf(str1,"%02x",&c1);

        b.push_back((c<<4)+c1);
    }
    return b;
}


int main() {
    KeyPair test("loh1");
    auto keypair = test.getKeyRSApair();

    unsigned char str[]=
            "I am encrypted4332048230948-2308402934702384-2384092384-0234-20384-2384-2384-234";

    unsigned char iv[EVP_MAX_IV_LENGTH]={};
    unsigned char *encrypted_key=(unsigned char*)malloc(EVP_PKEY_size(keypair.first));
    int encrypted_key_len=EVP_PKEY_size(keypair.first);

    std::vector<unsigned char> cyphered = envelope_seal(&keypair.first,str,strlen((char*)str),
                                                 &encrypted_key,&encrypted_key_len,iv);
    std::string cypheredString=GetHex(cyphered);

    std::vector<unsigned char> cypheredbinary=GetBinary(cypheredString);
    std::vector<unsigned char> plaintext = envelope_open(keypair.second,&cypheredbinary[0],cypheredbinary.size(),encrypted_key,encrypted_key_len,iv);

    for(char c:plaintext)
        printf("%c",c);

    return 0;
}
