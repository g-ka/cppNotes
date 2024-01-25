#include <iostream>

int main(){

  std::string strings[] = {"dog","racecar","car"};
  const int SIZE = 3;

  // -- start --

  std::string prefix = strings[0];

  for(int i=1; i<SIZE; i++){
    for(int j=0; j<strings[i].length(); j++){
      if(prefix[j] != strings[i][j]){
        prefix.erase(j, prefix.length() - j);
        break;
      }
    }
    if(prefix.length() > strings[i].length())
    prefix.erase(strings[i].length(), prefix.length() - strings[i].length());
  }

  // --- end ---
 
  if(prefix == "") std::cout << "No prefix";
  else std::cout << prefix;

  return 0;
}