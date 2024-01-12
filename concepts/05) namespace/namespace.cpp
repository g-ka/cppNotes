#include <iostream>

// namespace is used to declare multiple variables with same name
// In below code we declared variable 'int x' three times, and yet no error is thrown because the concept of namespace is used

namespace first{
  int x = 1;
}

namespace second{
  int x = 2;
}

int main() {

  // Run the code with only any one set released from comments( (1) or (2) or (3) ):

  // 1)
  /*
  int x = 0;

  std::cout << x << "\n"; //output: 0
  std::cout << first::x << "\n"; //output: 1
  std::cout << second::x << "\n"; //output: 2
  */

  // 2)  
  /*
  using namespace first;

  std::cout << x << "\n"; //output: 1
  std::cout << first::x << "\n"; //output: 1
  std::cout << second::x; //output: 2
  */

  // 3)
  /*
  using namespace second;

  std::cout << x << "\n"; //output: 2
  std::cout << first::x << "\n"; //output: 1
  std::cout << second::x; //output: 2
  */

  return 0;
}