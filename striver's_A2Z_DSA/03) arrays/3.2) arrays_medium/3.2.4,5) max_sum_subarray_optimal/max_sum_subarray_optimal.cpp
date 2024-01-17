#include <iostream>

int maxSubarraySumOf(int a[], int);

int main(){

  int numbers[] = {5,4,-1,7,8};  
  const int SIZE = sizeof(numbers)/sizeof(int);
  int maxSum;

  maxSum = maxSubarraySumOf(numbers, SIZE);

  std::cout << "The subaray sum: " << maxSum;

  return 0;
}

int maxSubarraySumOf(int a[], const int SIZE){
  
  int startIndex = 0;
  int endIndex = 0;
  int startGain = 0;
  int endGain = 0;
  int betterStartIndex = -1;
  int maxSum = a[0]; // for calculating sum(could be removed)
  int tempSum = a[0]; // for calculating sum(could be removed)

  for(int i=1; i<SIZE; i++){
    endGain += a[i];
    tempSum += a[i]; // for calculating sum(could be removed)
    int currentStartGain = startGain;
    startGain -= a[i-1];
    if(startGain > 0 && startGain > currentStartGain){      
      betterStartIndex = i;
    }

    if(endGain > 0){
      endIndex = i;
      endGain = 0;
      maxSum = tempSum; // for calculating sum(could be removed)
      if(betterStartIndex != -1){
        maxSum += startGain; // for calculating sum(could be removed)
        startIndex = betterStartIndex;
        startGain = 0;
        betterStartIndex = -1;        
      }
      tempSum = maxSum; // for calculating sum(could be removed)
    }
  }

  if(maxSum < 0) std::cout << "Large sum subarray: []";
  else{
    std::cout << "Large sum subarray: [";
    for(int i=startIndex; i<=endIndex; i++){
      if(i==endIndex) std::cout << a[i];
      else std::cout << a[i] << ", ";
    }
    std::cout << "]\n";
  }
  
  return maxSum;

}