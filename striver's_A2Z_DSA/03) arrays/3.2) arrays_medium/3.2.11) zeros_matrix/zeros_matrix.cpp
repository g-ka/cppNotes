#include <iostream>

int main(){

  int numbers[][3] = {
    {1,1,1},
    {1,0,1},
    {1,1,1}
  };
  const int cols = 3;
  const int rows = 3;

  // -- start --

  int row[rows];
  int col[cols];

  std::fill(row, row+rows, 1);
  std::fill(col, col+cols, 1);

  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      if(numbers[i][j] == 0){
        row[i] = 0;
        col[j] = 0;
      }
    }
  }

  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      numbers[i][j] = row[i]*col[j]*numbers[i][j];
    }
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