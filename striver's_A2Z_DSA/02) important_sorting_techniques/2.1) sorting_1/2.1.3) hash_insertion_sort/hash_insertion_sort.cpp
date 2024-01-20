#include <iostream>

void sort(int a[], int);

int main(){

  int numbers[] = {9,13,2,5,30,21,3,8,27,1};
  const int SIZE = sizeof(numbers)/sizeof(int);

  sort(numbers, SIZE);

  return 0;
}

void sort(int a[], const int SIZE){

  // -- start --

  int hash[SIZE];

  for(int i=0; i<SIZE; i++){
    int count = 0;
    for(int j=0; j<SIZE; j++){
      if(i != j && a[i] > a[j]) count++;
    }
    hash[count] = a[i];
  }

  // -- end --

  for(int number : hash) std::cout << number << " ";

}