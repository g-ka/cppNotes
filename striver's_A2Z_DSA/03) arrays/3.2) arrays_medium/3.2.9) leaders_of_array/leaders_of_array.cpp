#include <iostream>

void displayLeaders(int a[], int);

int main(){

  int numbers[] = {10, 22, 12, 3, 0, 6};
  const int SIZE = sizeof(numbers)/sizeof(int);

  displayLeaders(numbers, SIZE);

  return 0;
}

void displayLeaders(int a[], const int SIZE){

  int leaders[SIZE];
  int li = 0;
  int tempMax = INT_MIN;

  for(int i=SIZE-1; i>=0; i--){
    if(a[i] > tempMax){
      tempMax = a[i];
      leaders[li] = a[i];
      li++;
    }
  }

  for(int i=0; i<li; i++) std::cout << leaders[i] << " ";

}