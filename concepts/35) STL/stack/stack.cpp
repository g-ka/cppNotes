#include <iostream>
#include <bits/stdc++.h>

int main(){

  std::stack<int> s;
  s.push(1); // {1}
  s.push(2); // {1,2}
  s.push(3); // {1,2,3}
  s.push(4); // {1,2,3,4}
  s.emplace(5); // {1,2,3,4,5} => emplace is same as push

  std::cout << s.top() << "\n"; // 5
  std::cout << s.size() << "\n"; // 5
  s.pop();
  std::cout << s.top() << "\n"; // 4
  std::cout << s.size() << "\n"; // 4
  std::cout << s.empty() << "\n"; // false - 0

  s.top() += 10; // top() is both read and write
  std::cout << s.top(); // 14

  return 0;
}