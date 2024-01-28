#include <iostream>
#include <bits/stdc++.h>

void mergeRanges(std::vector<std::vector<int>>& v);
void sort(std::vector<std::vector<int>>& v, int low, int high);
void merge(std::vector<std::vector<int>>& v, int low, int mid, int high);

int main(){

  std::vector<std::vector<int>> v{{16,18}, {1,3}, {8,10}, {10,15}, {8,12}, {2,6}};

  mergeRanges(v);
  
  for(auto i: v){
    for(auto j: i){
      std::cout << j << " ";
    }
    std::cout << "\n";
  }

  return 0;
}

void mergeRanges(std::vector<std::vector<int>>& v){

  sort(v, 0, v.size()-1);

  for(int i=1; i<v.size(); i++){
    if(v[i-1][0] == v[i][0] || (v[i-1][0] < v[i][0] && v[i-1][1] > v[i][0])){
      std::vector<int> merge{v[i-1][0], std::max(v[i-1][1], v[i][1])};
      v.erase(v.begin()+i-1, v.begin()+i+1);
      v.insert(v.begin()+i-1, merge);
      i--;
    }else if(v[i-1][1] == v[i][0]){
      std::vector<int> merge{v[i-1][0], v[i][1]};
      v.erase(v.begin()+i-1, v.begin()+i+1);
      v.insert(v.begin()+i-1, merge);
      i--;
    }
  }

}

void sort(std::vector<std::vector<int>>& v, int low, int high){
  if(low == high) return;
  int mid = (low + high)/2;
  sort(v, low, mid);
  sort(v, mid+1, high);
  merge(v, low, mid, high);
}

void merge(std::vector<std::vector<int>>& v, int low, int mid, int high){
  int p1 = low;
  int p2 = mid+1;
  std::vector<std::vector<int>> temp;

  while(p1<=mid && p2<=high){
    if(v[p1][0] <= v[p2][0]){
      temp.push_back(v[p1]);
      p1++;
    }else{
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