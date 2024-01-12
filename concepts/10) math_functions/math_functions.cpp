#include <iostream>
#include <cmath>

int main() {

  double x = 3;
  double y = 4;
  double z;

  z = std::max(x,y); //z = 4
  z = std::min(x,y); //z = 3

  z = pow(3,2); //z = 9 => 3 power to 2
  z = sqrt(9); //z = 3
  z = abs(-3); //z = 3
  z = round(3.14); //z = 3
  z = ceil(3.14); //z = 4
  z = floor(3.89); //z = 3

  return 0;
}