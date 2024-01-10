#include <iostream>

/* 
*** 
to get input from user, shift the output from 'output window' to 'terminal window', by doing the following steps:
file -> preferences -> settings -> search: 'coderunner' -> check/tick the 'Code-runner: Run In Terminal' box
***
*/

/*
cin >> => extraction operator => extract information from user
cout << => insertion operator => insert information to user
*/

int main() {

  std::string name;
  int age;
  std::string programmingLanguage;

  std::cout << "What is your full name: ";
  std::getline(std::cin, name);  //input: kaphil athithiya
  // std::cin >> name => breaks when there are blank spaces in input
  // std::getline(std::cin, name) => works with input that contains blank spaces(srings with blank spaces)

  std::cout << "What is your age: ";
  std::cin >> age; //input: 20

  std::cout << "What is your most preferred programming language: ";
  std::cin >> programmingLanguage; //input: JS

  std::cout << "Hello " << name << '\n';
  //'output: kaphil' if 'std::cin >> name' is used
  //'output: kaphil athithiya' if 'std::getline(std::cin, name)' is used
  std::cout << "you are " << age << " years old\n"; //output: 20
  std::cout << "you are a " << programmingLanguage << " developer"; //output: JS

  return 0;
}

// std::cin produces automatic '/n', pushing the ouput to new line and thus if we use std::getline(std::cin, name) 
// after std::cin >>, getline gets '/n' as its input and skips getting its intended input.
// To prevent that use std::getline(std::cin >> std::ws, name)