#include <iostream>

int nestParenCount(std::string s);

int main(){

  std::string s = "(1)+((2))+(((3)))";
  int count = 0;

  count = nestParenCount(s);

  std::cout << count;

  return 0;
}

int nestParenCount(std::string s){
  int maxCount = 0;
  int count = 0;

  for(int i=0; i<s.length(); i++){
    if(s[i] == '('){
      count++;
      if(count > maxCount) maxCount = count;
    }else if(s[i] == ')') count--;
  }

  return maxCount;
}