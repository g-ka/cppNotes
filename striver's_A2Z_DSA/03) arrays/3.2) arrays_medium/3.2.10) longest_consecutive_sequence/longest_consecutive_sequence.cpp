#include <iostream>

int longestSequence(int a[], const int SIZE);

int main(){

  int numbers[] = {3, 8, 5, 7, 6};
  const int SIZE = sizeof(numbers)/sizeof(int);
  int result;

  result = longestSequence(numbers, SIZE);

  std::cout << "The longest consecutive sequence is of length: " << result;

  return 0;
}

int longestSequence(int a[], const int SIZE){

  int largeNum = a[0];

  for(int i=0; i<SIZE; i++){
    if(a[i] > largeNum) largeNum = a[i];
  }

  int hash[largeNum+1];
  std::fill(hash, hash+largeNum+1, -1);

  for(int i=0; i<SIZE; i++) hash[a[i]] = i;

  int longLength = 0;
  int length = 0;

  for(int i=0; i<largeNum+1; i++){
    if(hash[i] == -1) length = 0;
    else{
      length++;
      if(length > longLength) longLength = length;
    }
  }

  return longLength;

}