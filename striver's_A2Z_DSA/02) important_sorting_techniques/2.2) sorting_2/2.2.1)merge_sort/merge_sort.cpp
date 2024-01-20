#include <iostream>

void sort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);

int main(){

  int numbers[] = {3,2,4,1,3};
  const int SIZE = sizeof(numbers)/sizeof(int);

  sort(numbers, 0, SIZE-1);

  for(int number : numbers) std::cout << number << " ";

  return 0;
}

void sort(int a[], int low, int high){
  if(low == high) return;
  int mid = (low+high)/2;
  sort(a, low, mid);
  sort(a, mid+1, high);
  merge(a, low, mid, high);
}

void merge(int a[], int low, int mid, int high){
  int p1 = low;
  int p2 = mid+1;
  int temp[high-low+1];
  int index = 0;

  while(p1<=mid && p2<=high){
    if(a[p1] < a[p2]){
      temp[index] = a[p1];
      p1++;
      index++;
    }else{
      temp[index] = a[p2];
      p2++;
      index++;
    }
  }

  while(p1<=mid){
    temp[index] = a[p1];
    p1++;
    index++;
  }
  while(p2<=high){
    temp[index] = a[p2];
    p2++;
    index++;
  }

  index = 0;
  for(int i=low; i<=high; i++){
    a[i] = temp[index];
    index++;
  }
}