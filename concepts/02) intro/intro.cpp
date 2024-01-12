#include <iostream>
/* 
-- iostream => standard input output stream
-- iostream library is an object-oriented library that provides input and output functionality using streams.
-- A stream is a sequence of bytes. You can think of it as an abstraction representing a device. 
-- You can perform I/O operations on the device via this abstraction. You must include iostream header file to input and output from a C++ program.
*/

int main() {
  std::cout << "I like pizza!" << std::endl;
  // std::cout => standard character output
  // std::endl => enters new line  
  std::cout << "It's really good." << "\n";
  // An alternative for entering new line => \n
  std::cout << "You should try it.";

  return 0;
  // returning 0 => indicates success
  // returning 1 => indicates failed
}