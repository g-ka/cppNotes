#include <iostream>

int romanConvert(std::string s);
int r2n(char r);

int main(){

  std::string s = "MCMXCIV";
  int num;

  num = romanConvert(s);

  std::cout << num;

  return 0;
}

int romanConvert(std::string s){
  int num = r2n(s[0]);

  for(int i=1; i<s.length(); i++){
    int current = r2n(s[i]);
    int prev = r2n(s[i-1]);
    if(current <= prev) num += current;
    else num -= 2*prev - current;
  }

  return num;
}

int r2n(char r){
  switch(r){
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
  }
}