#include <iostream>
#include <bits/stdc++.h>

int longSubarraySumOf(std::vector<int> v, const int k);

int main(){

  std::vector<int> numbers{-1,2,3,-2,1,3,2,2,-1,-2};
  int maxLength;

  maxLength = longSubarraySumOf(numbers, 4);

  std::cout << maxLength;

  return 0;
}

int longSubarraySumOf(std::vector<int> v, const int k){
  int maxLength = 0;
  int sum = 0;
  std::vector<int> hash;

  for(int i=0; i<v.size(); i++){
    sum += v[i];
    hash.push_back(sum);
  }

  for(int i=0; i<hash.size(); i++){
    if(hash[i] == k && i+1>maxLength) maxLength = i+1;
    else{
      for(int j=0; j<i+1; j++){
        if(hash[j] == hash[i]-k && i-j>maxLength){
          maxLength = i-j;
          break;
        }
      }
    }
  }

  return maxLength;
}