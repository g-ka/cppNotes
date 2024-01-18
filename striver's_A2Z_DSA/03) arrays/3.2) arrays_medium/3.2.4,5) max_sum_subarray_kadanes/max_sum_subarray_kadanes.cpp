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
  int tempStart = -1;
  int start = -1;
  int end = -1;

  for(int i=0; i<SIZE; i++){
    if(tempSum == 0) tempStart = i;
    tempSum += a[i];
    if(tempSum > maxSum){
      maxSum = tempSum;
      start = tempStart;
      end = i;
    }
    if(tempSum < 0) tempSum = 0;
  }

  for(int i=start; i<=end; i++) std::cout << a[i] << " ";

  return (maxSum == INT_MIN ? 0 : maxSum);

}