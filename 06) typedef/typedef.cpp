#include <iostream>

// 1)
// 'typedef' keyword is used to create an alias/nick_name/alternative_name for a datatype:
typedef std::string text_t;
typedef int number_t;
// So here we've created an alternative name for std::string and int as text_t and number_t respectively.
// ending the alternative name created with typedef with _t is a naming convention

// 2)
// we can also create an alternative name with 'using' keyword:
/*
using text_t = std::string;
using number_t = int;
*/

int main() {

  text_t name = "kapilan";
  number_t age = 20;

  std::cout << name << "\n"; //output: kapilan
  std::cout << age; //output: 20

  return 0;
}

// 'typedef' and 'using' kwyword is used alternatively but using is used quite often than typedef