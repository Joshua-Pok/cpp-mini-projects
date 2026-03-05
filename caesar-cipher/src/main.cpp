#include <iostream>
#include <string>
#include "cipher.h"


//in cpp, main can accept two parameters int argc: arg count and char* argv[] array of c style strings
int main(int argc, char* argv[]){


	std::string res;
	std::cout << "Caesar Cipher Initialized!" << std::endl;

	//check if argc is exactly 3
	if (argc != 4){
		std::cout << "Usage: ./caesar <mode> <message> <shift>" << std::endl;
		return 0;
	}

	std::string message = argv[2];
	int shift = std::stoi(argv[3]);
	std::string flag = argv[1];


	if (flag == "-e"){
		res = encrypt(message, shift);
	}else if(flag == "-d"){
		res = decrypt(message, shift);
	}else{
		std::cout << "Invalid Flag: Usage: -d decrypt, -e encrypt";
		return 0;
	}

	std::cout << res << std::endl;
	
	return 0;
}
