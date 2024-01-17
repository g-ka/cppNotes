#include <iostream>

int maxSubarraySumOf(int a[], int);

int main(){

  int numbers[] = {-2,1,-3,4,-1,2,1,-5,4};  
  const int SIZE = sizeof(numbers)/sizeof(int);
  int maxSum;

  maxSum = maxSubarraySumOf(numbers, SIZE);

  std::cout << "The maximum subaray sum: " << maxSum;

  return 0;
}

int maxSubarraySumOf(int a[], const int SIZE){
  int maxSum = INT_MIN;

  for(int i=0; i<SIZE; i++){
    for(int j=0; j<SIZE-i; j++){
      int sum = 0;
      for(int k=j; k<i+j+1; k++){
        sum += a[k];
      }
      if(sum > maxSum) maxSum = sum;
    }
  }

  return maxSum;
}