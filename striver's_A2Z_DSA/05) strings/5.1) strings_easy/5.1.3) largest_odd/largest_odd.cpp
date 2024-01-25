#include <iostream>
#include <string>

std::string largeOdd(std::string str);

int main(){

  std::string number = "52";
  std::string largeOddNum;

  largeOddNum = largeOdd(number);

  if(largeOddNum == "") std::cout << "Doesn't exist";
  else std::cout << largeOddNum;

  return 0;
}

std::string largeOdd(std::string str){

  std::string largeOdd = "";
  std::string number = "";

  for(int i=0; i<str.length(); i++){
    number += str[i];
    if(int(str[i])%2) largeOdd = number;
  }

  return largeOdd;

}