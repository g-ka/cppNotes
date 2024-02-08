#include <iostream>
#include <bits/stdc++.h>

int countOf(std::vector<int> v, int target);

int main(){

  std::vector<int> v{1,2,3,4,4,4,9,10};

  int count = countOf(v, 4);

  std::cout << count;

  return 0;
}

int countOf(std::vector<int> v, int target){
  int first = -1;
  int second = -1;
  int start = 0;
  int end = v.size() - 1;
  while(start!=end){
    int middle = (end - start)/2 + start;
    if(v[middle] < target) start = middle + 1;
    else end = middle;
  }
  if(v[start] != target) return 0;
  else{
    first = start;
    start = 0;
    end = v.size() - 1;
    while(start!=end){
      int middle = (end - start)/2 + start;
      if(v[middle] <= target) start = middle + 1;
      else end = middle;
    }
    if(v[start] == target) second = start;
    else second = start - 1;
  }
  return second - first + 1;
}