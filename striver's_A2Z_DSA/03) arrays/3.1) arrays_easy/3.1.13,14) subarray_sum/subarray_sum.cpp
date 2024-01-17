#include <iostream>

void longSubarraySumOf(int a[], int, int);

int main(){

  int numbers[] = {1,-3,-2,1,4,-5,6,-7,9,0,-2,1,4};
  const int SIZE = sizeof(numbers)/sizeof(int);
  const int K = 4;

  longSubarraySumOf(numbers, SIZE, K);

  return 0;
}

void longSubarraySumOf(int a[], const int SIZE, const int K){
  int s = 0;
  int e = 0;
  int ss = -1;
  int se= -2;
  int sum = a[0];
  // int count = 0;

  while(e<SIZE){
    // count++;
    if(sum > K){
      sum -= a[s];
      s++;
    }else if(sum == K){
      if(e-s > se-ss){
        ss = s;
        se = e;
      }
      sum -= a[s];
      s++;
    }else{
      e++;
      sum += a[e];
    }
  }  

// std::cout << "count: " << count << "\n";
  if(se == -1) std::cout << "No such subarray exist";
  else{
    for(int i=ss; i<=se; i++){
      std::cout << a[i] << " ";
    }
  }  
}