#include <iostream>

/*
string methods:
.length() => returns length(no.of characters including blank spaces) of the string
.empty() => returns 1(true) if string is empty, else returns 0(false)
.clear() => makes a string empty("")
.append("value") => appends "value" at the end of the original string
.at(index) => returns the character at the specified index from the string
.insert(index, "value") => inserts the "value" at the specified index of the string
.find("value") => returns the starting index of the value from the string
.erase(startIndex, x) => removes x number of chracters from the specified index of the string(this is similar to .splice() array method in JS)
*/

int main() {

  std::string name = "G Kaphil";

  std::cout << name.length() << "\n"; //output: 8

  std::cout << name.empty() << '\n'; //output: 0(false)

  name.clear();
  std::cout << name.empty() << '\n'; //output: 1(true)

  name.append("gk athithiya");
  std::cout << name << "\n"; //output: gk athithiya

  std::cout << name.at(0) << '\n'; //output: g

  name.insert(1,"t_");
  std::cout << name << "\n"; //output: gt_k athithiya

  std::cout << name.find('k') << "\n"; //output: 3
  std::cout << name.find("athi") << "\n"; //output: 5

  name.erase(3, 4);
  std::cout << name; //output: gt_hithiya

  return 0;
}