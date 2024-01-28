#include <bits/stdc++.h>
// the above line includes all libraries such as string.h, math.h and so on

// A new data type => pair => declared as std::pair<int, int>
// This is in the utility library

int main(){

  std::pair<int, int> p1 = {1,3};
  std::cout << "p1: " << p1.first << " " << p1.second << "\n";

  std::pair<int , std::pair<int, int>> p2 = {1,{2,3}};
  std::cout << "p2: " << p2.first << " " << p2.second.first << " " << p2.second.second << "\n";

  std::pair<int, int> arr[] = {{1,2}, {3,4}, {5,6}};
  std::cout << "arr: " << arr[0].first << " " << arr[0].second;

  return 0;
}