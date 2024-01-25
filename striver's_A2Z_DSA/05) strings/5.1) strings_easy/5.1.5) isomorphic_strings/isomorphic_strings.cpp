#include <iostream>

bool isIsomorphic(std::string s, std::string t);

int main(){

  std::string s = "foo";
  std::string t = "bar";
  bool result;

  result = isIsomorphic(s,t);

  std::cout << result;

  return 0;
}

bool isIsomorphic(std::string s, std::string t){

  std::string tCopy = t;

  for(int i=0; i<s.length(); i++){
    std::cout << tCopy << "\n";
    std::cout << t << "\n";
    if(t[i] != '0'){
      char temp = t[i];
      for(int j=0; j<t.length(); j++){
        if(t[j] == temp){
          tCopy[j] = s[i];
          t[j] = '0';
        }
      }
    }
  }

  if(s == tCopy) return true;
  else return false;

}