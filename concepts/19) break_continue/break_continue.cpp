#include <iostream>

/*
break => breaks out of a loop(we've already used this keyword in chapter-12-switch_statements)
continue => skips current iteration
*/

int main() {

  for(int i=1; i<20; i++){
    if(i == 13){
      continue;
    }else if(i == 18){
      break;
    }
    std::cout << "|" << i;
  }

  return 0;
}