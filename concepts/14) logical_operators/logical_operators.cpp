#include <iostream>

/*
There are three logical operators:
-- && => and
-- || => or
-- ! => not
*/

int main() {

  double temp;
  bool isManageable;

  std::cout << "Enter the temperature(celsius): ";
  std::cin >> temp;

  if(temp >= 5 && temp <= 30){
    std::cout << "The temperature is good.";
  }else if(temp >= 0 || temp <= 35){
    std::cout << "The temperature is bad, yet not so bad.";
  }

  std::cout << "\nIs it manageable(type 1 if yes, else 0): ";
  std::cin >> isManageable;

  if(!isManageable){
    std::cout << "Don't worry, I will set a appropriate temperature uisng AC";
  }else{
    std::cout << "Great!";
  }

  return 0;
}