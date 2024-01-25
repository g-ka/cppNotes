#include <iostream>

bool isAnagram(std::string s, std::string t);

int main(){

  std::string s = "anagram";
  std::string t = "aganram";
  bool result;

  result = isAnagram(s,t);

  if(result) std::cout << "true";
  else std::cout << "false";

  return 0;
}

bool isAnagram(std::string s, std::string t){

  int alpha[26];
  std::fill(alpha, alpha+26, 0);

  for(int i=0; i<s.length(); i++) alpha[((int) s[i]) - 97]++;

  for(int i=0; i<t.length(); i++){
    alpha[((int) t[i]) - 97]--;
    if(alpha[((int) t[i]) - 97] < 0) return false;
  }

  return true;

}