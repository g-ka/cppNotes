#include <iostream>

int main() {

  int age;

  std::cout << "Enter your age: ";
  std::cin >> age;

  if(age >= 100){
    std::cout << "You're too old for this website, sorry.";
  }else if(age == 18){
    std::cout << "You're almost there, come back next year.";
  }else if(age >= 18){
    std::cout << "Welcome to the website!";
  }else if(age <= 0){
    std::cout << "You aren't born yet.";
  }else{
    std::cout << "You must be above 18 years old, sorry!";
  }

  return 0;
}