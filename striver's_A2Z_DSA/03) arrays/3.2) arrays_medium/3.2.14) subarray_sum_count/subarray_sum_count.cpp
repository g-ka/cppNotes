#include <iostream>

int subarraySumCount(int a[], const int SIZE, const int K);

int main(){

  int numbers[] = {1,2,3};
  const int SIZE = sizeof(numbers)/sizeof(int);
  int count;

  count = subarraySumCount(numbers, SIZE, 3);

  std::cout << "The number of such subaray: " << count;

  return 0;
}

int subarraySumCount(int a[], const int SIZE, const int K){
  
  int s = 0;
  int e = 0;
  int sum = a[0];
  int count = 0;

  while(e<SIZE){
    if(sum > K){
      if(s!=e){
        sum -= a[s];
        s++;        
      }else{
        e++;
        sum += a[e];
      }
    }else if(sum == K){
      count++;
      e++;
      sum += a[e];
    }else{
      e++;
      sum += a[e];
    }
  }

  return count;

}