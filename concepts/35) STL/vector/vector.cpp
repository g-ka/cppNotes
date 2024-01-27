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

  std::vector<int> v3(5, 100); // creates a vector with first 5 element as 100 => 100 100 100 100 100

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

  // ----- 4) element deletion:

  for(int i=3; i<=10; i++){
    v1.push_back(i);
  }

  // "earse" takes pointer as input and deletes the element stored at the memory location to which the pointer points
  // NOTE: [start, end)
  v1.erase(v1.begin(), v1.begin()+2); // deletes first and second element in v1 => 3 4 5 6 7 8 9 10  
  v1.erase(v1.begin()+3); // deletes element at index 3 => 3 4 5 7 8 9 10

  // ----- 5) element insertion:

  v1.insert(v1.begin(), 2); // 2 3 4 5 7 8 9 10
  v1.insert(v1.begin()+3, 11); // 2 3 4 11 5 7 8 9 10
  v1.insert(v1.begin()+1, 2, 12); // 2 12 12 3 4 11 5 7 8 9 10

  // ----- 6) useful methods:

  // size():
  std::cout << "size: " << v1.size() << "\n"; // 11

  // pop_back(): deletes the last element
  v1.pop_back(); // 2 12 12 3 4 11 5 7 8 9

  // swap():
  v1.swap(v3); 
  // v1: 100 100 100 100 100
  // v3: 2 12 12 3 4 11 5 7 8 9

  // clear():
  v1.clear(); // v1: {}

  // empty(): returns true(1) if vector is empty else returns false(0)
  std::cout << "isEmpty: " << v1.empty();

  return 0;
}