#include <iostream>

/*
new keywords:
-- switch => sets the switch cases
-- case => sets each case 
-- break => stops the compiler traversing through further cases after the matched case
-- default => sets a default case if none of any other defined case is matched
*/

int main() {

  int month;

  std::cout << "Enter month number(1-12): ";
  std::cin >> month;

  switch(month){

    case 1:{
      std::cout << "Its January";
      break;
    }case 2:{
      std::cout << "Its February";
      break;
    }case 3:{
      std::cout << "Its March";
      break;
    }case 4:{
      std::cout << "Its April";
      break;
    }case 5:{
      std::cout << "Its May";
      break;
    }case 6:{
      std::cout << "Its June";
      break;
    }case 7:{
      std::cout << "Its July";
      break;
    }case 8:{
      std::cout << "Its August";
      break;
    }case 9:{
      std::cout << "Its September";
      break;
    }case 10:{
      std::cout << "Its October";
      break;
    }case 11:{
      std::cout << "Its November";
      break;
    }case 12:{
      std::cout << "Its December";      
      break;
    }default:{
      std::cout << "Please enter numbers only between 1 to 12";
    }

  }

  return 0;
}