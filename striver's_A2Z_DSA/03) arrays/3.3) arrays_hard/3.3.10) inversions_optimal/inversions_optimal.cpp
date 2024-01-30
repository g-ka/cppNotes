#include <iostream>
#include <bits/stdc++.h>

void inversionNum(std::vector<int> a, int low, int high);
void merge(std::vector<int> a, int low, int mid, int high);

namespace global{
  int count = 0;
}

int main(){

  std::vector<int> v{8,7,6,5,4,3,2,1};

  inversionNum(v, 0, v.size()-1);

  std::cout << global::count;

  return 0;
}

void inversionNum(std::vector<int> a, int low, int high){
  if(low == high) return;
  int mid = (low+high)/2;
  inversionNum(a, low, mid);
  inversionNum(a, mid+1, high);
  merge(a, low, mid, high);
}

void merge(std::vector<int> a, int low, int mid, int high){
  int p1 = low;
  int p2 = mid+1;
  int temp[high-low+1];
  int index = 0;

  while(p1<=mid && p2<=high){
    if(a[p1] < a[p2]){      
      temp[index] = a[p1];
      p1++;
      index++;
    }else{
      global::count++;
      temp[index] = a[p2];
      p2++;
      index++;
    }
  }

  while(p1<=mid){
    global::count += high - mid;
    temp[index] = a[p1];
    if(p1==mid) global::count -= high - mid;
    p1++;
    index++;
  }
  while(p2<=high){
    temp[index] = a[p2];
    p2++;
    index++;
  }

  index = 0;
  for(int i=low; i<=high; i++){
    a[i] = temp[index];
    index++;
  }
}