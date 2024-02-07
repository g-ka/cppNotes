#include <iostream>
#include <bits/stdc++.h>

int lowerBound(std::vector<int> nums, int target);

int main(){

  std::vector<int> nums{3,5,8,15,19};

  int index = lowerBound(nums, 9);

  std::cout << index;

  return 0;
}

int lowerBound(std::vector<int> nums, int target){
  int start = 0;
  int end = nums.size() - 1;
  while(start!=end){
    int middle = (end - start)/2 + start;
    if(nums[middle] < target) start = middle + 1;
    else end = middle;
  }
  if(start == nums.size() - 1) return nums.size();
  else if(start == 0) return 0;
  else return start;
}