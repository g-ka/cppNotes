#include <iostream>
#include <algorithm> // this library contains the reverse() method

/*
syntax:
reverse(start, end) 
=> start = array + index(inclusive) and end = array + index(exclusive)

-- helps in reversing the specified portion of the array
*/

int main(){
  int numbers[10] = {1,2,3,4,5,6,7,8,9,10};

  std::reverse(numbers, numbers+3); // reverses sub-array from index 0 to 2
  
  for(int number : numbers){
    std::cout << number << " ";
  }
}