#include <iostream>
#include <bits/stdc++.h>

std::vector<std::vector<int>> fourSum(std::vector<int> v, int k);
std::vector<std::vector<int>> threeSum(std::vector<int> v, int k);
std::vector<std::vector<int>> twoSum(std::vector<int>, int k);
void sort(std::vector<int>& v, int low, int high);
void merge(std::vector<int>& v, int low, int mid, int high);

int main(){

  std::vector<int> v{1,0,-1,0,-2,2};
  std::vector<std::vector<int>> sum4result;

  sum4result = fourSum(v, 0);

  for(auto i: sum4result){
    for(auto j: i){
      std::cout << j << " ";
    }
    std::cout << "\n";
  }

  return 0;
}

std::vector<std::vector<int>> fourSum(std::vector<int> v, int k){
  sort(v, 0, v.size()-1);
  std::vector<std::vector<int>> sum4result;
  for(int i=0; i<v.size(); i++){
    int temp = v[0];
    v.erase(v.begin());
    std::vector<std::vector<int>> sum = threeSum(v, k-temp);
    if(!sum.empty()){
      for(auto i: sum){
        i.push_back(temp);
        sum4result.push_back(i);
      }
    }
  }
  // for unique quadruplets:
  // -----
  // sort(sum4result);
  // auto ip = std::unique(sum4result.begin(), sum4result.begin() + sum4result.size());
  // sum4result.resize(std::distance(sum4result.begin(), ip));
  // -----
  return sum4result;
}

std::vector<std::vector<int>> threeSum(std::vector<int> v, int k){
  std::vector<std::vector<int>> sum3result;
  for(int i=0; i<v.size(); i++){
    int temp = v[0];
    v.erase(v.begin());
    std::vector<std::vector<int>> sum = twoSum(v, k-temp);
    if(!sum.empty()){
      for(auto i: sum){
        i.push_back(temp);
        sum3result.push_back(i);
      }
    }    
  }
  return sum3result;
}

std::vector<std::vector<int>> twoSum(std::vector<int> v, int k){
  std::vector<std::vector<int>> sum2result;
  int start = 0;
  int end = v.size() - 1;
  while(start < end){
    if(v[start] + v[end] == k){
      std::vector<int> sum{v[start], v[end]};
      sum2result.push_back(sum);
      if(v[start+1] == v[start]) start++;
      else if(v[end-1] == v[end]) end--;
      else start++;
    }else if(v[start] + v[end] < k) start++;
    else end--;
  }
  return sum2result;
}

void sort(std::vector<int>& v, int low, int high){
  if(low == high) return;
  int mid = (low+high)/2;
  sort(v, low, mid);
  sort(v, mid+1, high);
  merge(v, low, mid, high);
}

void merge(std::vector<int>& v, int low, int mid, int high){
  std::vector<int> temp;
  int p1 = low;
  int p2 = mid+1;

  while(p1<=mid && p2<=high){
    if(v[p1] <= v[p2]){
      temp.push_back(v[p1]);
      p1++;
    }
    else{
      temp.push_back(v[p2]);
      p2++;
    }
  }

  while(p1<=mid){
    temp.push_back(v[p1]);
    p1++;
  }
  while(p2<=high){
    temp.push_back(v[p2]);
    p2++;
  }

  int index = 0;  
  for(int i=low; i<=high; i++){
    v[i] = temp[index];
    index++;
  }  
}