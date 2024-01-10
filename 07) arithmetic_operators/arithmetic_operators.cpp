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
  // every variables(LHS and RHS) involved in division operation must be of 'double' datatype, to earn a decimal result. Else the decimal portion will be truncated.

  std::cout << result << "\n"; //output: 10.5
  std::cout<< 5+2-3*10/5; //output: 1
  // arithmetic operators follow BODMAS precendence

  return 0;
}