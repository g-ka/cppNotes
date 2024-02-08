#include <iostream>
#include <bits/stdc++.h>

std::pair<int, int> firstAndLast(std::vector<int> v, int target);

int main(){

  std::vector<int> v{1,2,3,4,4,4,9,10};

  std::pair<int, int> result = firstAndLast(v, 4);

  std::cout << result.first << " " << result.second;

  return 0;
}

std::pair<int, int> firstAndLast(std::vector<int> v, int target){
  int first = -1;
  int second = -1;
  int start = 0;
  int end = v.size() - 1;
  while(start!=end){
    int middle = (end - start)/2 + start;
    if(v[middle] < target) start = middle + 1;
    else end = middle;
  }
  if(v[start] != target) return {first, second};
  else{
    first = start;
    start = 0;
    end = v.size() - 1;
    while(start!=end){
      int middle = (end - start)/2 + start;
      if(v[middle] <= target) start = middle + 1;
      else end = middle;
    }
    second = start - 1;
  }
  return {first, second};
}