#ifndef TYPES_H 
#define TYPES_H
#include <string>
enum class Element { // enum class ensures we cant accidentally treat elements
                     // like members
  Fire,
  Water,
  Earth,
  None

};

struct Character {
  std::string name;
  int hp;
  int attack;
  int defense;
  Element type;
};


std::string elementToString(Element e);


#endif
