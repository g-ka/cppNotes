#include <iostream>
#include <bits/stdc++.h>

int main(){

  std::queue<int> q;

  q.push(1); // {1}
  q.push(3); // {1,3}
  q.emplace(5); // {1,3,5}
  std::cout << q.front() << "\n"; // 1
  std::cout << q.back() << "\n"; // 5
  std::cout << q.size() << "\n"; // 3
  q.pop();
  std::cout << q.front() << "\n"; // 3
  std::cout << q.back() << "\n"; // 5
  std::cout << q.size() << "\n"; // 2

  q.front() += 10; // fornt() and back() are both read and write
  std::cout << q.front(); // 13

  return 0;
}