#include <iostream>

void removeDupOf(int a[], int &SIZE);

int main(){

  int numbers[] = {1,1,1,2,2,3,3,3,55,78,89,89,90,91};
  int SIZE = sizeof(numbers)/sizeof(int);

  removeDupOf(numbers, SIZE);

  for(int i=0; i<SIZE; i++){
    std::cout << numbers[i] << " ";
  }

  return 0;
}

void removeDupOf(int a[], int &SIZE){

  int prevElement = a[0];

  for(int i=1; i<SIZE; i++){
    if(a[i] == prevElement){
      for(int j=i; j<SIZE-1; j++){
        a[j] = a[j+1];
      }
      i--;
      SIZE--;
    }else prevElement = a[i];
  }

}