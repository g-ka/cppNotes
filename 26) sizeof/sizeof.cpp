#include <iostream>

// sizeof() => returns the size in bytes of a variable, data type, object, class, etc..

int main() {

  int num = 10;
  std::string name = "kaphil";
  double decimal = 23.45;
  bool isGood = true;
  char initial = 'G';
  char initials[] = {'G', 'R', 'P', 'A', 'S'};

  std::cout << sizeof(int) << " " << sizeof(num) << "\n"; //output: 4 4 
  std::cout << sizeof(std::string) << " " << sizeof(name) << "\n"; //output: 32 32 
  // string variable stores the reference and thus its size will always remian 32 bytes no matter the number of 
  // characters it have
  std::cout << sizeof(double) << " " << sizeof(decimal) << "\n"; //output: 8 8 
  std::cout << sizeof(bool) << " " << sizeof(isGood) << "\n"; //output: 1 1 
  std::cout << sizeof(char) << " " << sizeof(initial) << "\n"; //output: 1 1 
  std::cout << sizeof(initials) << "\n"; //output: 5

  // length of an array:
  std::cout << sizeof(initials)/sizeof(initials[0]) << " elements\n"; // 5
  std::cout << sizeof(initials)/sizeof(char) << " elements"; // 5

  return 0;
}