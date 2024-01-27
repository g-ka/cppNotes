#include <bits/stdc++.h>
// the above line includes all libraries such as string.h, math.h and so on

// vector is just an array with dynamic memory

int main(){

  // ----- 1) declaring vector:

  std::vector<int> v1;

  v1.push_back(1);
  v1.emplace_back(2); // faster version of push_back()

  std::vector<std::pair<int, int>> v2;

  v2.push_back({1,2});
  v2.emplace_back(3,4); // automatically assumes it to pair

  std::vector<int> v3(5, 100); // creates a vector with first 5 element as 100

  std::vector<int> v4(v1); // creates v4 and copies v1 into it

  // ----- 2) displaying vector:

  std::cout << "v1: " << v1[0] << " " << v1[1] << "\n";

  std::vector<int>::iterator start = v1.begin(); // this makes variable 'start' to point to the first element's memory location
  // of vector v1

  std::cout << "v1(begin pointer): " << *start << " ";
  start++;
  std::cout << *start << "\n";

  std::vector<int>::iterator end = v1.end(); // variable 'end' will point to the memory location next to the last 
  // element(not the last element)
  std::cout << "v1(end pointer): " << *(end-1) << " " << *(end -2) << "\n";

  // ----- 3) iterating through vector:

  std::cout << "v1(using iteration): ";
  for(std::vector<int>::iterator start = v1.begin(); start != v1.end(); start++){
    std::cout << *start << " ";
  }

  // 'auto' keyword will automatically assign the datatype to the variable according to the value we initialize it with:
  auto num = 12;
  std::cout << "\n" << "num datatype: " << typeid(num).name() << "\n";

  std::cout << "v1(using auto-iteration): ";
  for(auto start = v1.begin(); start!=v1.end(); start++){
    std::cout << *start << " ";
  }std::cout << "\n";

  // shortest version to iterate:
  std::cout << "v1(shortest iteration): ";
  for(auto start: v1){
    std::cout << start << " ";
  }std::cout << "\n";

  return 0;
}