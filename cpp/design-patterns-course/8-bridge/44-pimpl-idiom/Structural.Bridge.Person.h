#pragma once
#include <string>

struct Person
{
  std::string name;

  // Simply declares that te PersonImpl class will be defines within the Person
  // class.
  class PersonImpl;

  // A pointer to the PersonImpl class. This is effectivley used to implement
  // the persno class. It does not matte whether or not the PersonImpl class itself
  // is declared / defined within teh Person class.
  PersonImpl *impl; // bridge - not necessarily inner class, can vary

  Person();
  ~Person();

  void greet();
};
