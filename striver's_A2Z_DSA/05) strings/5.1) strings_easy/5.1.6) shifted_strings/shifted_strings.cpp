#include <iostream>

bool isShifted(std::string s, std::string g);

int main(){

  std::string s = "abcde";
  std::string g = "cdeab";
  bool result;

  result = isShifted(s,g);

  if(result) std::cout << "True";
  else std::cout << "False";

  return 0;
}

bool isShifted(std::string s, std::string g){
  for(int i=0; i<s.length(); i++){
    int k = i;
    for(int j=0; j<g.length(); j++){
      if(k == s.length()) k = 0;
      if(s[k] != g[j]) break;
      else if(j == g.length() - 1) return true;
      k++;
    }
  }

  return false;
}