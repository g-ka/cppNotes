#include <iostream>

/*
typeconversion => converting a value from one datatype to another datatype:
-- implicit => automatic typeconversion
-- explicit => doing typeconversion manually by prefixing a datatype keyword
*/

int main() {

  int weight = 70.25;
  std::cout << weight << "\n"; //output: 70
  // weight is initialized with a decimal value(70.25), but its datatype is 'int', thus 70.25(double) is implicity converted to 70(int)

  double age = (int) 20.6;
  std::cout << age << "\n"; //output: 20
  // age can take 20.6 because its datatype is double but still age outputs 20 and not 20.6 as we explicity converted it to an int(20) using (int) prefix

  // In chapter 07)arithmetic_operators we've seen 'Any operation between double and int will result in a double value'. This is because the int value will be implicitly converted to double during computation.

  char letter = 100;
  std::cout << letter << "\n"; //output: d
  // letter got initialized with a int value(100), but its datatype is 'char', thus 100(int) is implicitly converted to its corresponding ascii value d(char) => ASCII value of d: 100

  std::cout << (char) 101; //output: e

  return 0;
}