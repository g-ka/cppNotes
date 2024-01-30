#include <iostream>
#include <bits/stdc++.h>

std::pair<int, int> findMissRep(std::vector<int> v);

int main(){

  std::vector<int> v{1,2,3,2};
  std::pair<int, int> result;

  result = findMissRep(v);

  std::cout << result.first << " " << result.second;

  return 0;
}

std::pair<int, int> findMissRep(std::vector<int> v){

  std::pair<int, int> result;
  int hash[v.size()+1];
  std::fill(hash, hash+v.size()+1, 0);

  for(auto i: v){
    hash[i]++;
  }

  for(int i=0; i<v.size()+1; i++){
    if(hash[i]>1) result.first = i;
    if(hash[i]<1) result.second = i;
  }

  return result;

}