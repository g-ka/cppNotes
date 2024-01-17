#include <iostream>

void sort(int a[], int);

int main(){

  int numbers[] = {2,2,2,2,0,0,1,0};
  const int SIZE = sizeof(numbers)/sizeof(int);

  sort(numbers, SIZE);

  for(int number : numbers){
    std::cout << number << " ";
  }

  return 0;
}

void sort(int a[], const int SIZE){
  int p1 = -1;
  int p2 = -1;

  for(int i=0; i<SIZE; i++){
    if(a[i] == 1 && p1 == -1 && p2 == -1) p1 = i;
    if(a[i] == 2 && p2 == -1) p2 = i;

    if(a[i] == 0 && p1 != -1 && p2 != -1){
      a[p1] = 0;
      a[p2] = 1;
      a[i] = 2;
      p1++;
      p2++;
    }else if(a[i] == 0 && p1 != -1 && p2 == -1){
      a[p1] = 0;
      a[i] = 1;
      p1++;
    }else if(a[i] == 0 && p1 == -1 && p2 != -1){
      a[p2] = 0;
      a[i] = 2;
      p2++;
    }

    if(a[i] == 1 && p1 != -1 && p2 != -1){
      a[p2] = 1;
      a[i] = 2;
      p2++;
    }else if(a[i] == 1 && p1 == -1 && p2 != -1){
      a[p2] = 1;
      a[i] = 2;
      p1 = p2;
      p2++;
    }
  }
}