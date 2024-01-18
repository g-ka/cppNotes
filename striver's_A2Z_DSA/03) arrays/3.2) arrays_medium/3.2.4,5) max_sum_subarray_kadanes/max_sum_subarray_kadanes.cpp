#include <iostream>

int maxSubarraySumOf(int a[], int);

int main(){

  int numbers[] = {5,4,-1,7,8};  
  const int SIZE = sizeof(numbers)/sizeof(int);
  int maxSum;

  maxSum = maxSubarraySumOf(numbers, SIZE);

  std::cout << "The maximum subarray sum: " << maxSum;

  return 0;
}

int maxSubarraySumOf(int a[], const int SIZE){
  
  int maxSum = INT_MIN;
  int tempSum = 0;

  for(int i=0; i<SIZE; i++){
    tempSum += a[i];
    if(tempSum > maxSum) maxSum = tempSum;
    if(tempSum < 0) tempSum = 0;
  }

  return (maxSum == INT_MIN ? 0 : maxSum);

}