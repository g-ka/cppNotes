#include <iostream>

std::string longSsPlaindrom(std::string s);
bool isPalindrome(std::string s);

int main(){

  std::string s = "fgsdkjfvbijvbsdihfwwwweeeewwwwwbsths";
  std::string result;

  result = longSsPlaindrom(s);

  std::cout << result;

  return 0;
}

std::string longSsPlaindrom(std::string s){
  std::string maxLengthSs = "";

  for(int i=0; i<s.length(); i++){
    for(int j=0; j<s.length()-i; j++){
      std::string ss = "";
      for(int k=j; k<j+i+1; k++){
        ss += s[k];
      }
      if(isPalindrome(ss) && ss.length() > maxLengthSs.length()) maxLengthSs = ss;
    }
  }

  return maxLengthSs;
}

bool isPalindrome(std::string s){
 for(int i=0; i<s.length()/2; i++){
  if(s[i] != s[s.length() - i - 1]) return false;
 }
 return true;
}
