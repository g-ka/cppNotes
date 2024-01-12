#include <iostream>

void swapByReference(std::string &x, std::string &y); // while declaring function which has reference 
// parameters, declare the variables also in declaration
void swapByValue(std::string, std::string);

int main() {

  std::string x = "kaphil";
  std::string y = "athithiya";
  std::string a = "tamil";
  std::string b = "selvi";

  swapByReference(x,y);
  swapByValue(a,b);

  std::cout << x << " " << y << "\n"; //output: athithiya kaphil
  std::cout << a << " " << b; //output: tamil selvi
  
  return 0;
}

void swapByReference(std::string &x, std::string &y){
  std::string temp = x;
  x = y;
  y = temp;
}

void swapByValue(std::string a, std::string b){
  std::string temp = a;
  a = b;
  b = temp;
}