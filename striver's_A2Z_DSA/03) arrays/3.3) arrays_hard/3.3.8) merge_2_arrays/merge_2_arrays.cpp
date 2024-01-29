#include <iostream>
#include <bits/stdc++.h>

void merge2arrays(std::vector<int>& v1, std::vector<int>& v2);

int main(){

  std::vector<int> v1{1, 8, 8};
  std::vector<int> v2{2, 3, 4, 5};

  merge2arrays(v1, v2);

  for(auto i: v1) std::cout << i << " ";
  std::cout << "\n";
  for(auto i: v2) std::cout << i << " ";

  return 0;
}

void merge2arrays(std::vector<int>& v1, std::vector<int>& v2){
  for(int p1=0; p1<v1.size(); p1++){
    if(v1[p1] > v2[0]){
      int temp = v1[p1];
      v1[p1] = v2[0];
      v2[0] = temp;
      for(int p2=0; v2[p2]>v2[p2+1] && p2<v2.size()-1; p2++){
        int temp = v2[p2];
        v2[p2] = v2[p2+1];
        v2[p2+1] = temp;
      }
    }
  }
}