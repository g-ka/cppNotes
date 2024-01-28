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
  int sum = 0;
  std::vector<int> hash;

  for(int i=0; i<v.size(); i++){
    sum += v[i];
    hash.push_back(sum);
  }

  for(int i=0; i<hash.size(); i++){
    if(hash[i] == 0 && i+1>maxLength) maxLength = i+1;
    else{
      for(int j=0; j<i+1; j++){
        if(hash[j] == hash[i] && i-j>maxLength){
          maxLength = i-j;
          break;
        }
      }
    }
  }

  return maxLength;
}