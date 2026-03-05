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
void printStats(const Character& c);
void attack(const Character& attacker, Character& defender);



namespace CombatConfig{


constexpr float ELEMENTAL_BOOST = 5.0f;
const float BASE_MULTIPLIER = 1.0f;

}

#endif
