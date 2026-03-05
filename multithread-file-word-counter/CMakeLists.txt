cmake_minimum_required(VERSION 3.10)
project(file_wordcounter)


set(CMAKE_CXX_STANDARD 17)

include_directories(include)


add_executable(wordcount src/main.cpp src/word_counter.cpp)
