#include <iostream>

void alternate(int a[], int);

int main(){

  int numbers[] = {1,2,-3,-1,-2,3};
  const int SIZE = sizeof(numbers)/sizeof(int);

  alternate(numbers, SIZE);

  for(int number : numbers){
    std::cout << number << " ";
  }

  return 0;
}

void alternate(int a[], const int SIZE){

  int negatives[SIZE/2];
  int positives[SIZE/2];
  int ni = 0;
  int pi = 0;

  std::fill(negatives, negatives+SIZE/2, -1);
  std::fill(positives, positives+SIZE/2, -1);

  for(int i=0; i<SIZE; i++){
    if(i%2 == 0 && a[i] < 0){
      negatives[ni] = i;
      if(positives[ni] != -1){
        int temp = a[negatives[ni]];
        a[negatives[ni]] = a[positives[ni]];
        a[positives[ni]] = temp;
      }
      ni++;
    }else if(i%2 != 0 && a[i] > 0){
      positives[pi] = i;
      if(negatives[pi] != -1){
        int temp = a[positives[pi]];
        a[positives[pi]] = a[negatives[pi]];
        a[negatives[pi]] = temp;
      }
      pi++;
    }
  }

}