#include <iostream>

int main() {

  const double PI = 3.14;
  // declare a variable with 'const' keyword along with its datatype keyword(double in above case) to create constant variables
  // const variables are generally declared with uppercase letters
  double radius = 2.2;
  double circumference = 2*PI*radius;

  std::cout << circumference << "cm"; //output: 13.816cm

  return 0;
}