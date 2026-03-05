#include "../include/word_counter.h"
#include <fstream>
#include <iostream>
#include <mutex>

void countWordsInFile(std::string filename, std::string targetWord,
                      std::mutex mtx) {
  int localCount = 0;
  std::ifstream inputFile(filename);
  std::string word;
  while (inputFile >> word) {
    {
      std::lock_guard<std::mutex> guard(mtx); //lock guard is a safe lock that automatically unlocks
      std::cout << word << std::endl;
    }

    if (word == targetWord) {
      localCount++;
    }
  }
  {
    std::lock_guard<std::mutex> guard(mtx);
    std::cout << filename << "contains" << localCount << "occurences of "
              << targetWord;
  } // scopes the guard so when it goes out of scope it is automatically
    // unlocked
}
