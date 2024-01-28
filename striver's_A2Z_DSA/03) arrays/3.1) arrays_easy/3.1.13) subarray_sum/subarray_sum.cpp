#include <iostream>

void longSubarraySumOf(int a[], int, int);

int main(){

  int numbers[] = {2,3,5,1,9};
  const int SIZE = sizeof(numbers)/sizeof(int);
  const int K = 10;

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
      if(s!=e){
        sum -= a[s];
        s++;
      }else{
        e++;
        sum += a[e];
      }      
    }else if(sum == K){
      if(e-s > se-ss){
        ss = s;
        se = e;
      }
      e++;
      sum += a[e];
    }else{
      e++;
      sum += a[e];
    }
  }  

// std::cout << "count: " << count << "\n";
  if(ss == -1) std::cout << "No such subarray exist";
  else{
    for(int i=ss; i<=se; i++){
      std::cout << a[i] << " ";
    }
  }  
}