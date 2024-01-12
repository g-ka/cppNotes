#include <iostream>

/*
-- A function's name and parameters together is known as its signature.
-- Multiple functions can share same name given that they have different 'function signature'.
-- Multiple functions with same name are called overloaded functions
*/

void display(std::string);
void display(int);
// void display(int); => not allowed - (refer line-42)
void display(double);

int main() {

  std::string name = "kaphil";
  int age = 20;
  int height = 6;
  double weight = 69.69;

  display(name);
  display(age);
  // display(height); => not allowed - (refer line-42)
  display(weight);
  

  return 0;
}

void display(std::string name) {
  std::cout << "Hello " << name << "\n";
}

void display(int age) {
  std::cout << "Your age is " << age << "\n";
}

/* 
void display(int height) {
   std::cout << "Your height is " << height << "ft\n";
 }
-- The function display(int height) is not allowed as it has same signature(same name and same no.of parameters 
with same datatype) as 'display(int age)' 
*/ 

void display(double weight) {
  std::cout << "You weigh " << weight << "Kgs\n";
}