#include <iostream>

bool isPalindrome(std::string);

int main(){

  std::string word;
  bool result;

  std::cout << "Enter a word: ";
  std::cin >> word;

  result = isPalindrome(word);

  std::cout << (result ? "Its a palindrome" : "Its not a palindrome");

  return 0;
}

bool isPalindrome(std::string word){
  for(int i=0; i<word.length(); i++){
    if(word.at(i) != word.at(word.length() - 1 -i)){
      return false;
    }
  }
  return true;
}