#include <iostream>
#include <bits/stdc++.h>

std::vector<std::vector<int>> pascalTri(int numRows);

int main(){

  std::vector<std::vector<int>> result;

  result = pascalTri(5);

  for(auto i: result){
    for(auto j: i){
      std::cout << j << " ";
    }
    std::cout << "\n";
  }

  return 0;  
}

std::vector<std::vector<int>> pascalTri(int numRows){
  std::vector<int> firstRow(1,1);
  std::vector<int> prevRow(2,1);
  std::vector<std::vector<int>> triangle;

  if(numRows == 1){
      triangle.push_back(firstRow);
      return triangle;
  }
  else if(numRows == 2){
      triangle.push_back(firstRow);
      triangle.push_back(prevRow);
      return triangle;
  }
  else{
      triangle.push_back(firstRow);
      triangle.push_back(prevRow);

      for(int i=2; i<numRows; i++){
          std::vector<int> row;

          for(int j=0; j<i+1; j++){
              if(j == 0 || j == i) row.push_back(1);
              else row.push_back(prevRow[j-1] + prevRow[j]);
          }

          triangle.push_back(row);

          prevRow.swap(row);
      }    

      return triangle;
  }
}