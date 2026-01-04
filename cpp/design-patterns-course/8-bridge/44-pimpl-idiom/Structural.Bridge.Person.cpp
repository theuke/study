#include "Person.h"

// Defines the PersonImpl class
struct Person::PersonImpl
{
  void greet(Person* p);
};

// Defiens the greet method within the PersonImpl class
void Person::PersonImpl::greet(Person* p)
{
  printf("hello %s", p->name.c_str());
}

// Defines the default Person construct by initializing the impl member variable
// in the initializer list.
Person::Person()
  : impl(new PersonImpl)
{
}

// Defines the Person destructor. The destruction procedure consists just of
// deleting the dynamically created impl.
Person::~Person()
{
  delete impl;
}

// Defines the Person greet method which is simply a wrapper that calls the
// greet method of the impl.
void Person::greet()
{
  impl->greet(this);
}


