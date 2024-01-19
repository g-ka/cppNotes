#include <iostream>
#include <algorithm>

int main(){

  char numbers[][4] = {
    {'a','b','c','d'},
    {'e','f','g','h'},
    {'i','j','k','l'},
    {'m','n','o','p'}
  };
  const int rows = 4;
  const int cols = 4;

  // -- start --

  for(int i=0; i<rows; i++){
    for(int j=i; j<cols; j++){
      int temp = numbers[i][j];
      numbers[i][j] = numbers[j][i];
      numbers[j][i] = temp;
    }
  }

  for(int i=0; i<rows; i++){
    std::reverse(numbers[i], numbers[i]+cols);
  }

  // -- end --

  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      std::cout << numbers[i][j] << " ";
    }
    std::cout << "\n";
  }

  return 0;
}