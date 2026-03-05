#include "custom_vector.h"
#include <iostream>

int main(){

	CustomVector<int> myVec(2);
	myVec.push_back(1);
	myVec.push_back(2);
	myVec.push_back(3);


	CustomVector<int> myVec2 = myVec;

	myVec2.set(0, 5);


	for (int i = 0; i < 3; i++){
		
		std::cout << myVec.at(i) << std::endl;
	}

	std::cout << myVec.size() << std::endl;
	std::cout << myVec.capacity() <<std::endl;


	CustomVector<std::string> words(2);
	CustomVector<double> prices(2);


	words.push_back("Hello");
	words.push_back("World!");
	prices.push_back(100);
	prices.push_back(200);


	for (int i = 0; i < 2; i++){
		std::cout << words.at(i) << std::endl;
		std::cout << prices.at(i) << std::endl;
	}
}
