#include "types.h"
#include <iostream>
#include <string>


void printStats(const Character& c){

	std::cout << elementToString(c.type) << std::endl;

}


std::string elementToString(Element e){ // we cannot directly print enum class we need a helper
	switch (e) {

		case(Element::Fire){ return "Fire" };
		case(Element::Water){ return "Water" };
		case(Element::Earth){ return "Earth" };
		case(Element::None){ return "None" };
	}
};
