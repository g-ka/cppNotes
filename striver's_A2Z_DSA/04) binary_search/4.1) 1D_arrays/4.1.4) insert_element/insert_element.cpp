#include <iostream>
#include <bits/stdc++.h>

int insertAt(std::vector<int> nums, int target);

int main(){

  std::vector<int> nums{1,3,5,6};

  int index = insertAt(nums, 2);

  std::cout << index;

  return 0;
}

int insertAt(std::vector<int> nums, int target){
  int start = 0;
  int end = nums.size() - 1;
  while(start!=end){
      int middle = (end - start)/2 + start;
      if(nums[middle] < target) start = middle + 1;
      else end = middle;
  }
  if(start == nums.size()-1 && nums[start] < target) return start + 1;        
  else return start;
}
