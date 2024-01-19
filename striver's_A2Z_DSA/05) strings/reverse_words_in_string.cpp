#include <iostream>

int main(){

  std::string line = "enna da paakura eh? rightu!";
  int length = line.length();
  int gaps = 0;

  for(int i=0; i<length; i++){
    if(line[i] == ' ') gaps++;
  }  

  int wordsCount = gaps + 1;
  std::string words[wordsCount];
  std::string subString = "";
  int index = 0;

  for(int i=0; i<length; i++){    
    if(line[i] == ' '){
      words[index] = subString;
      index++;
      subString = "";
    }
    else subString += line[i];

    if(i == length-1) words[index] = subString;
  }

  line = "";

  for(int i=wordsCount-1; i>=0; i--){
    line += words[i]+" ";
  }

  std::cout << line;

  return 0;
}