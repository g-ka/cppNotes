#include <iostream>

/*
syntax:
int array[no_of_rows][no_of_elements_in_each_row/no_of_columns] = {{row1}, {row2}, {row3}, ...};

-- Not specifying the no.of rows will let us initialize the array with any number of rows of our wish
*/

int main() {

  std::string cars[][3] = {
    {"camaro", "corvette", "silverado"},
    {"alto", "800", "omni"},
    {"indigo", "nano", "punch"}
  };
  const int ROW_SIZE = sizeof(cars)/sizeof(cars[0]);

  for(int i=0; i<ROW_SIZE; i++){
    for(std::string car : cars[i]){
      std::cout << car << " ";
    }    
    std::cout << std::endl;
  }

  return 0;
}