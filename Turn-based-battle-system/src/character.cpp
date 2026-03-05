#include "types.h"
#include <iostream>
#include <string>

void printStats(const Character &c) {

  std::cout << elementToString(c.type) << std::endl;
  std::cout << c.name << std::endl;
  std::cout << c.hp << std::endl;
  std::cout << c.attack << std::endl;
  std::cout << c.defense << std::endl;
}

std::string elementToString(
    Element e) { // we cannot directly print enum class we need a helper
  switch (e) {

  case Element::Fire:
    return "Fire";
  case Element::Water:
    return "Water";
  case Element::Earth:
    return "Earth";
  case Element::None:
    return "None";
  default:
    return "Unknown";
  }
};

void attack(const Character &attacker, Character &defender) {
  // attacker is const because we only need to read stats
  // defender is not const because we need to deduct HP!
  int base_damage = attacker.attack - defender.defense;

  float multiplier = CombatConfig::BASE_MULTIPLIER;

  if (attacker.type == Element::Water && defender.type == Element::Fire) {
    multiplier = CombatConfig::ELEMENTAL_BOOST;
  } else if (attacker.type == Element::Fire &&
             defender.type == Element::Earth) {
    multiplier = CombatConfig::ELEMENTAL_BOOST;
  } else {
    multiplier = CombatConfig::BASE_MULTIPLIER;
  }

  int final_damage = base_damage * multiplier;

  defender.hp -= final_damage;
  if (defender.hp < 0) {
    defender.hp = 0;
  }

  std::cout << attacker.name << " attacks " << defender.name << " for "
            << final_damage << " damage!" << std::endl;
  std::cout << "Defender HP:" << defender.hp << std::endl;
}
