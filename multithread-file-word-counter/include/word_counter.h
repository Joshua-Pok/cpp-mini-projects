#ifndef WORD_COUNTER_H
#define WORD_COUNTER_H


#include <mutex>
#include <string>
void countWordsInFile(std::string filename, std::string targetWord, std::mutex& mtx, int&globalCount);


#endif

