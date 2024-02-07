#include <iostream>
#include <bits/stdc++.h>

int upperBound(std::vector<int> nums, int target);

int main(){

  std::vector<int> nums{3,5,8,9,15,19};

  int index = upperBound(nums, 9);

  std::cout << index;

  return 0;
}

int upperBound(std::vector<int> nums, int target){
  int start = 0;
	int end = nums.size() - 1;
	while(start!=end){
		int middle = (end - start)/2 + start;
		if(nums[middle] > target) end = middle;
		else start = middle + 1;		
	}
	if(start == nums.size() - 1 && nums[start] <= target) return start + 1;
	else return start;
}