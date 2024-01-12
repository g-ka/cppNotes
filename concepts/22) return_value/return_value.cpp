#include <iostream>
#include <cmath>

// return => stops the function and returns a value to the variable that encompasses the function

/* 
The datatype of the function should be same as that of the datatype of the value it returns
-- void function(){} => no return value
-- int function(){} => return value is of int datatype
-- double function(){} => reutrn value is of double datatype
-- and so on...
*/

double squareAreaCalculator(double); 
double cubeVolumeCalculator(double);

int main() {

  double length = 10;
  double squareArea;
  double cubeVolume;

  squareArea = squareAreaCalculator(length);
  cubeVolume = cubeVolumeCalculator(length);

  std::cout << "Area of square: " << squareArea << "m^2\n";
  std::cout << "Volume of cube: " << cubeVolume << "m^3";

  return 0;
}

double squareAreaCalculator(double length) {
  return pow(length, 2);
}

double cubeVolumeCalculator(double length) {
  return pow(length, 3);
}