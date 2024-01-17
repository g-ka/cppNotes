#include <iostream>

int maxOccurrOf(int a[], int);

int main(){

  int numbers[] = {7,6,8,1,6,6,2,6,6};
  const int SIZE = sizeof(numbers)/sizeof(int);
  int maxOccurNumber;

  maxOccurNumber = maxOccurrOf(numbers, SIZE);

  std::cout << "The maximum occurring number: " << maxOccurNumber;

  return 0;
}

int maxOccurrOf(int a[], const int SIZE){

  int largestNumber = a[0];

  for(int i=1; i<SIZE; i++) if(a[i] > largestNumber) largestNumber = a[i];

  int hash[largestNumber + 1];
  std::fill(hash, hash+largestNumber+1, 0);

  for(int i=0; i<SIZE; i++) hash[a[i]]++;

  for(int i=0; i<largestNumber+1; i++) if(hash[i] > SIZE/2) return i;
}