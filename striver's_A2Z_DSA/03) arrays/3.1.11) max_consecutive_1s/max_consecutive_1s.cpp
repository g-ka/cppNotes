#include <iostream>

int maxConsecutive1sIn(int a[], int);

int main(){

  int numbers[] = {1, 0, 1, 1, 0, 1};
  const int SIZE = sizeof(numbers)/sizeof(int);
  int maxConsecutive1s;

  maxConsecutive1s = maxConsecutive1sIn(numbers, SIZE);

  std::cout << "Numbers of max consecutive 1s: " << maxConsecutive1s;

  return 0;
}

int maxConsecutive1sIn(int a[], const int SIZE){
  int max1s = 0;
  int tempMax1s = 0;

  for(int i=0; i<SIZE; i++){
    if(a[i]) {
      tempMax1s++;
      if(max1s < tempMax1s) max1s = tempMax1s;
    }
    else tempMax1s = 0;
  }

  return max1s;
}