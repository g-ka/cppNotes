#include <iostream>
#include <cmath>

bool isPalindrome(int);

int main(){
  
  int number;
  bool result;

  std::cout << "Enter a number: ";
  std::cin >> number;

  result = isPalindrome(number);

  std::cout << (result ? "Its a palindrome" : "Its not a palindrome");

  return 0;
}

// optimal way to reverse a number(unlike 1.4.2) and check for palindrome:
bool isPalindrome(int number){

  int tempNumber = abs(number);
  int reversedNumber = 0;

  while(tempNumber){
    reversedNumber = (reversedNumber*10) + tempNumber%10;
    tempNumber = floor(tempNumber/10); 
  }

  return reversedNumber == abs(number) ? true : false;

}