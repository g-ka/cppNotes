#include <iostream>
#include <bits/stdc++.h>

int longest0ss(std::vector<int> v);

int main(){

  std::vector<int> v{6, -2, 2, -8, 1, 7, 4, -10};
  int maxLength;

  maxLength = longest0ss(v);

  std::cout << maxLength;

  return 0;
}

int longest0ss(std::vector<int> v){
  int maxLength = 0;
  for(int i=0; i<v.size(); i++){
    for(int j=0; j<v.size()-i; j++){
      int sum = 0;
      for(int k=j; k<j+i+1; k++){
        sum += v[k];
      }
      if(sum == 0 && i+1 > maxLength) maxLength = i+1;
    }
  }
  return maxLength;
}