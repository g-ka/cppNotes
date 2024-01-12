#include <iostream>

int main() {

  double count = 21;

  /*
  add => +, ++, +=
  subtract => -, --, -=
  multiply => *, *=
  division => /, /=
  remainder => %
  */

  double result = count/2;
  // Any operation between double and int will result in a double value

  std::cout << result << "\n"; //output: 10.5
  std::cout<< 5+2-3*10/5; //output: 1
  // arithmetic operators follow BODMAS precendence

  return 0;
}