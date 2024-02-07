#include <iostream>
#include <bits/stdc++.h>

int findNum(std::vector<int> nums, int target);

int main(){

  std::vector<int> nums{-1,0,3,5,9,12};

  int index = findNum(nums, 9);

  std::cout << index;

  return 0;
}

int findNum(std::vector<int> nums, int target){
  int start = 0;
  int end = nums.size() - 1;
  while(start<=end){
    int middle = (end - start)/2 + start;
    if(nums[middle] == target) return middle;
    else if(nums[middle] < target) start = middle + 1;
    else end = middle - 1;    
  }
  return -1;
}