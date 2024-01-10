#include <iostream>

int main() {

  int x; // declaration
  x = 5; // assignment
  int y = 10; // initialization => declaration + assignment

  // datatypes:
  // 1) int => whole number
  int age = 20;
  int year = 2024;
  int weight = 70.5; // The decimal portion will be truncated

  std::cout << weight << "\n"; //output: 70

  // 2) double => whole number + decimal number 
  double temperature = 10.5;
  double cgpa = 6.2;  

  std::cout << temperature << '\n'; //output: 10.5

  // 3) char => only one character
  char initial = 'G';
  char acronym = 'KA';

  std::cout << initial << "\n"; //output: G
  std::cout << acronym << '\n'; //output: A => also throws a warning because only one char can be stored using 'char'
  // char should be declared in single quotes, double quotes will throw an error

  // 4) boolean => true or false
  bool student = true;
  bool forSale = false;

  std::cout << student << "\n"; //output: 1
  std::cout << forSale << '\n'; //output: 0

  // 5) string => multiple characters 
  // string is an object datatype
  std::string name = "g kaphil athithiya";  

  std::cout << name << '\n';
  std::cout << "Hello " << name;
  // string should be declared in double quotes, single quotes will throw an error

  return 0;
}