
#include "contacts.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

// std::map under the hood is a balanced binary tree
void addContact(std::map<std::string, Contact> &notebook, std::string name,
                std::string phoneNumber, std::string email,
                bool isFavourite = false) {

  if (notebook.count(name) > 0) {
    std::cout << "Name already exists in notebook" << std::endl;
    return;
  }

  notebook[name] = Contact{phoneNumber, email, isFavourite};
}

void findContact(const std::map<std::string, Contact> &notebook,
                 std::string name) {

  auto it = notebook.find(
      name); // map.find() returns an iterator pointing to the element if it
             // exists, if it does not exist it returns map.end()
  if (it == notebook.end()) {
    std::cout << "Contact not found!" << std::endl;
    return;
  }

  std::cout << it->first << std::endl;
  std::cout << it->second.phoneNumber << std::endl;
  std::cout << it->second.Email << std::endl;
}

void showFavourites(const std::map<std::string, Contact> &notebook) {
  std::vector<std::string> res;
  for (auto &pair : notebook) {
    if (pair.second.isFavourite)
      res.push_back(pair.first);
  }

  for (std::string &name : res) {
    std::cout << name << std::endl;
  }

  return;
}

int main() {
  std::map<std::string, Contact> notebook;

  addContact(notebook, "Alice", "90119248", "Alice@gmail.com", true);
  addContact(notebook, "Bob", "90228412", "Bob@gmail.com");
  addContact(notebook, "Charlie", "92482422", "Charlie@gmail.com");

  for (std::map<std::string, Contact>::iterator it = notebook.begin();
       it != notebook.end(); ++it) {
    std::cout << it->first
              << std::endl; // first is the key, second is the contact
  }

  findContact(notebook, "Bob");
  findContact(notebook, "Joshua");

  showFavourites(notebook);

  return 0;
}
