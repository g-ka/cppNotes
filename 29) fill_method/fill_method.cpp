#include <iostream>

/*
syntax:
fill(start_address, end_address, value)

-- Helps in filling the array with the specified value from the start to end address
*/

int main() {

  std::string foodItems[10];
  const int SIZE = sizeof(foodItems)/sizeof(std::string);

  fill(foodItems, foodItems + 10, "kool");

  for(std::string food : foodItems) {
    std::cout << food << "\n";
  }

  return 0;
}