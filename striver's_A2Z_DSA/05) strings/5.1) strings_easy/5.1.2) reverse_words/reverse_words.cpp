#include <iostream>

std::string reverseWords(std::string s);

int main(){

  std::string s = "  hello world  ";
  std::string sReverse;

  sReverse = reverseWords(s);

  std::cout << "|" << sReverse << "|";

  return 0;
}

std::string reverseWords(std::string s){

  bool isDone = false;
  int wordCount = 0;

  for(int i=0; i<s.length(); i++){
    if(s[i] != ' ') isDone = true;
    else if(s[i] == ' ' && isDone){
      wordCount++;
      isDone = false;
    }
    if(i == s.length()-1 && isDone){
      wordCount++;
      isDone = false;
    }
  }

  std::string words[wordCount];
  std::string word = "";
  int index = 0;

  for(int i=0; i<s.length(); i++){
    if(s[i] != ' '){
      word += s[i];
      isDone = true;
    }else if(s[i] == ' ' && isDone){
      words[index] = word;
      index++;
      word = "";
      isDone = false;
    }
    if(i == s.length()-1 && isDone) words[index] = word;
  }

  s = "";

  for(int i=wordCount-1; i>=0; i--){
    s += words[i];
    if(i) s += " ";
  }

  return s;

}