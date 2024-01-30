#include <iostream>
#include <bits/stdc++.h>

std::vector<int> findMissRep(std::vector<int> v);

int main(){

  std::vector<int> v{1,2,3,2};
  std::vector<int> result;

  result = findMissRep(v);

  for(auto i: result) std::cout << i << " ";

  return 0;
}

std::vector<int> findMissRep(std::vector<int> v){

  std::vector<int> result{-1, -1};
  int sum1 = 0;
  int sum2 = 0; 

  for(auto i: v){
    sum1 += i;
    sum2 += i*i;
  }

  int n = v.size();
  result[0] = 0.5*((sum2-n*(n+1)*(2*n+1)/6)/(sum1-n*(n+1)/2) + sum1-n*(n+1)/2);
  result[1] = result[0] + n*(n+1)/2 - sum1;

  return result;

}