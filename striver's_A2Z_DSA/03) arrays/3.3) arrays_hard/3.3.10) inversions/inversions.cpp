#include <iostream>
#include <bits/stdc++.h>

int inversionNum(std::vector<int> v);

int main(){

  std::vector<int> v{15, 28, 11, 20, 14, 7, 14, 2, 15, 4, 22, 19, 17, 1, 26, 6, 20, 2, 6};
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