#include <iostream>

std::string longSsPlaindrom(std::string s);

int main(){

  std::string s = "fyfvladzpbfudkklrwq";
  std::string result;

  result = longSsPlaindrom(s);

  std::cout << result;

  return 0;
}

std::string longSsPlaindrom(std::string s){
  std::string ss = "";
  std::string maxSs = "";
  int start = -1;
  int end = -1;

  maxSs += s[0]; // for setting the longest palindromic string as first char if no other 'ss' is found

  for(int i=0; i<s.length(); i++){
    ss = s[i];
    start = i-1;
    end = i+1;
    while(s[start] == s[end] && start >= 0 && end < s.length()){
      ss = s[start] + ss + s[end];
      start--;
      end++;
      if(ss.length() > maxSs.length()) maxSs = ss;
    }

    ss = "";
    start = i;
    end = i+1;
    while(s[start] == s[end] && start >= 0 && end < s.length()){
      ss = s[start] + ss + s[end];
      start--;
      end++;
      if(ss.length() > maxSs.length()) maxSs = ss;
    }
  }

  return maxSs;
}
