#include <iostream>

bool isIsomorphic(std::string s, std::string t);

int main(){

  std::string s = "13";
  std::string t = "42";
  bool result;

  result = isIsomorphic(s,t);

  if(result) std::cout << "true";
  else std::cout << "false";

  return 0;
}

bool isIsomorphic(std::string s, std::string t){

  int ascii[128];
  std::fill(ascii, ascii+128, -1);

  for(int i=0; i<s.length(); i++){
    if(ascii[(int) s[i]] == -1) ascii[(int) s[i]] = (int) t[i];
    else if(ascii[(int) s[i]] != (int) t[i]) return false;  
  }

  std::fill(ascii, ascii+128, -1);

  for(int i=0; i<t.length(); i++){
    if(ascii[(int) t[i]] == -1) ascii[(int) t[i]] = (int) s[i];
    else if(ascii[(int) t[i]] != (int) s[i]) return false;  
  }

  return true;

}