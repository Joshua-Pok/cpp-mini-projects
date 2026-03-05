#include "types.h"
#include <iostream>

int main(){


	Character Ignis{"Ignis", 50, 20, 5, Element::Fire};
	Character Aquaman{"Aquaman", 200, 20, 20, Element::Water};


	while(true){ //game loop
		
		attack(Aquaman, Ignis);
		if(Ignis.hp <= 0){
			std::cout << "The monster has been defeated!" << std::endl;
			break;
		}

		attack(Ignis, Aquaman);
		if(Aquaman.hp <= 0){
			std::cout << "GameOver! You were defeated!" << std::endl;
			break;
		}

	}

	

}
