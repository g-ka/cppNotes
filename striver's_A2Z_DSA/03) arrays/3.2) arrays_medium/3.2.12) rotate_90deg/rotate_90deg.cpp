#include <iostream>

int main(){

  int numbers[][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {10,11,12}
  };
  const int rows = 4;
  const int cols = 3;

  // -- start --

  const int rRows = cols;
  const int rCols = rows;

  int r[rRows][rCols];

  for(int i=0; i<rRows; i++){
    for(int j=0; j<rCols; j++){
      r[i][j] = numbers[rCols-1-j][i];
    }
  }

  // -- end --

  for(int i=0; i<rRows; i++){
    for(int j=0; j<rCols; j++){
      std::cout << r[i][j] << " ";
    }
    std::cout << "\n";
  }

  return 0;
}