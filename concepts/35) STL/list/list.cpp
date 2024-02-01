#include <iostream>
#include <bits/stdc++.h>

// list is all same as vector except that it gives methods to insert element at the front

int main(){

  std::list<int> myList{1,2,3};
  for(auto i: myList) std::cout << i << " ";
  std::cout << "\n";

  myList.push_front(0); // push_front();
  myList.emplace_front(-1); // emplace_front();
  for(auto i: myList) std::cout << i << " ";

  // all the methods of vector are applicable for list also

  return 0;
}