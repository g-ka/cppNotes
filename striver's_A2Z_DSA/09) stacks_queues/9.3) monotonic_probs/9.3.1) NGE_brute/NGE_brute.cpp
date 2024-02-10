#include <iostream>
#include <bits/stdc++.h>

std::vector<int> NGE(std::vector<int> v);

int main(){

  std::vector<int> v{3,10,4,2,1,2,6,1,7,2,9};

  std::vector<int> result = NGE(v);

  for(auto i: result) std::cout << i << " ";

  return 0;
}

std::vector<int> NGE(std::vector<int> v){
  std::vector<int> result;
  for(int i=0; i<v.size(); i++){
    int j = i + 1;
    while(v[i] > v[j%v.size()]) j++;
    if(j%v.size() == i) result.push_back(-1);
    else result.push_back(v[j%v.size()]);
  }
  return result;
}