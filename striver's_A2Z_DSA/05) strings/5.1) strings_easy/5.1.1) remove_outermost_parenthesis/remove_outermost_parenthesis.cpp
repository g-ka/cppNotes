#include <iostream>

std::string removeOutParenthesis(std::string str);

int main(){

  std::string parenthesis = "(()())(())(()(()))";
  std::string result;

  result = removeOutParenthesis(parenthesis);

  std::cout << result;

  return 0;
}

std::string removeOutParenthesis(std::string str){

  int start;
  int count = 0;

  for(int i=0; i<str.length(); i++){
    if(count == 0) start = i;
    if(str[i] == '(') count++;
    else count--;
    if(count == 0){
      str.erase(i,1);
      str.erase(start, 1);
      i -= 2;
    }
  }  

  return str;

}