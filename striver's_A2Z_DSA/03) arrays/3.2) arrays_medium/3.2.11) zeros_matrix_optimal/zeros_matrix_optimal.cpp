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

  int c0 = 1;

  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      if(numbers[i][j] == 0){
        if(i && j){
          numbers[i][0] = 0;
          numbers[0][j] = 0;
        }else{
          if(!i && !j){
            numbers[0][0] = 0;
            c0 = 0;
          }else if(!i && j){
            numbers[0][0] = 0;
          }else{
            c0 = 0;
          }
        }
      }      
    }
  }

  for(int i=1; i<rows; i++){
    for(int j=1; j<cols; j++){
      if(!numbers[i][0] || !numbers[0][j]) numbers[i][j] = 0;
    }
  }

  if(!numbers[0][0]){
    for(int i=0; i<cols; i++){
      numbers[0][i] = 0;
    }
  }
  if(!c0){
    for(int i=0; i<rows; i++){
      numbers[i][0] = 0;
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