#include <string>
#include "cipher.h"
#include <cctype>



std::string encrypt(std::string message, int shift){
	for(int i = 0; i < message.length(); i++){


		if (!std::isalpha(static_cast<unsigned char>(message[i]))){
			continue;
		}

		int new_char;
		if (message[i] >= 97 && message[i] <= 122){ //range for uppercase ASCII
			//in std::string is just integers stored next to each other
			new_char = ((message[i] - 'a' + shift + 26) % 26) + 'a';

		}else if(message[i] >= 65 && message[i] <= 90){
			new_char = ((message[i] - 'A' + shift + 26) % 26) + 'A';

		}else{
			new_char = message[i];
		}


		message[i] = new_char;
	}


	return message;
}


std::string decrypt(std::string message, int shift){

	return encrypt(message, -shift);

}
