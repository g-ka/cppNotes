#include <iostream>
#include <bits/stdc++.h>

int inversionNum(std::vector<int> v);

int main(){

  std::vector<int> v{8,7,6,5,4,3,2,1};
  int count;

  count = inversionNum(v);

  std::cout << count;

  return 0;
}

int inversionNum(std::vector<int> v){
  int count = 0;
  for(int i=0; i<v.size(); i++){
    for(int j=i+1; j<v.size(); j++){
      if(v[j] < v[i]) count++;
    }
  }
  return count;
}