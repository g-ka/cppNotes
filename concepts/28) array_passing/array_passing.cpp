#include <iostream>

/*
Things to note:
-- How an array is passed as an argument => line 20
-- How an array is recieved as a parameter => line 28
-- How array datatype is defined in function declaration => line 11
-- Array once recieved as a parameter by a function, will decay into a pointer
*/

int searchArray(int[], int, int);

int main() {

  int numbers[] = {1,2,3,4,5,6,7,8,9};
  int size = sizeof(numbers)/sizeof(numbers[0]);
  int toSearch = 0;
  int searchIndex;

  searchIndex = searchArray(numbers, size, toSearch);

  if(searchIndex == -1) std::cout << "No such element exist";
  else std::cout << "Its in index: " << searchIndex; //output: 2

  return 0;
}

int searchArray(int array[], int size, int searchElement) {
  for(int i=0; i<size; i++) {
    if(array[i] == searchElement) return i;
  }
  return -1;
}