#ifndef CIPHER_H
#define CIPHER_H


#include <string>


std::string encrypt(std::string message, int shift);
std::string decrypt(std::string message, int shift);


#endif
