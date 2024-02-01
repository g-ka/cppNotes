#include <iostream>
#include <bits/stdc++.h>

int maxProd(std::vector<int> v);

int main(){

  std::vector<int> v{2,-5,-2,-4,3};
  int result;

  result = maxProd(v);

  std::cout << result;

  return 0;
}

int maxProd(std::vector<int> v){
  int maxProd = v[0];
  int prod1 = 0;
  int prod2 = 0;
  int maxPosProd = 0;
  int posProd = 0;
  int isEncounter = false;

  for(int i=0; i<v.size(); i++){
      // products from start
      if(v[i] == 0) prod1 = 0;      
      if(prod1 == 0) prod1 += v[i];
      else prod1 *= v[i];
      if(prod1 > maxProd) maxProd = prod1;

      // products from end
      if(v[v.size() - i - 1] == 0) prod2 = 0;
      if(prod2 == 0) prod2 += v[v.size() - i - 1];
      else prod2 *= v[v.size() - i - 1];            
      if(prod2 > maxProd) maxProd = prod2;

      // pure positive number products
      if(v[i] <= 0) posProd = 0;
      else{
          isEncounter = true;
          if(posProd == 0) posProd += v[i];
          else posProd *= v[i];
          if(posProd > maxPosProd) maxPosProd = posProd;
      }
  }

  return (maxProd < maxPosProd && isEncounter ? maxPosProd : maxProd);
}