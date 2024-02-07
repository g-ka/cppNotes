#include <iostream>

int nestParentCount(std::string s);

int main(){

  std::string s = "(1)+((2))+(((3)))";
  int count = 0;

  count = nestParentCount(s);

  std::cout << count;

  return 0;
}

int nestParentCount(std::string s){
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