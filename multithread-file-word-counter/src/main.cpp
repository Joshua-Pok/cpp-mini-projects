#include "../include/word_counter.h"
#include <mutex>
#include <thread>
#include <vector>
#include <string>

int main(){


	std::vector<std::string> filenames = {"file1.txt", "file2.txt", "file3.txt"};
	std::vector<std::thread> myThreads;
	std::string target = "But";


	std::mutex mtx;
	//std::lock_guard locks a mutex when created and automatically unlocks it when it goes out of scope.


	for(std::string name : filenames){
		myThreads.push_back(std::thread(countWordsInFile, name, target, mtx)); //when the thread is running i give it the mutex
	};


	for(std::thread& t : myThreads){
		t.join(); //join tells the main program to wait until this thread is completely finished before exiting
	}





	

	return 0;
}
