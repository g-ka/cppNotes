#include <iostream>

/*
syntax:
fill(start, end, value) 
=> start = array + index(inclusive) and end = array + index(exclusive)

-- Helps in filling the array with the specified value from the start to end
*/

int main() {

  std::string foodItems[10];

  fill(foodItems, foodItems + 10, "kool"); // fill the specified value from index 0 to 9

  for(std::string food : foodItems) {
    std::cout << food << "\n";
  }

  return 0;
}