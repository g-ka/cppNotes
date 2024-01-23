#include <iostream>

void tripletsIn(int a[], const int SIZE, const int K);
void sort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);

int main(){

  int numbers[] = {-1,0,1,2,-1,-4};
  const int SIZE = sizeof(numbers)/sizeof(int);  

  tripletsIn(numbers, SIZE, 0);

  return 0;
}

void tripletsIn(int a[], const int SIZE, const int K){

  // sort:
  sort(a, 0, SIZE-1);

  // 2sum + pointer:  
  for(int i=0; i<SIZE; i++){    
    int start = i+1;
    int end = SIZE-1;    
    while(start<end){    

      if(a[start]+a[end]+a[i] > K) end--;
      else if(a[start]+a[end]+a[i] < K) start++;
      else{        
        std::cout << "[ " << start << ", " << end << ", " << i << " ]\n";
        start++;
      }
    }
  }

}

// merge sort:

void sort(int a[], int low, int high){
  if(low == high) return;
  int mid = (high+low)/2;
  sort(a, low, mid);
  sort(a, mid+1, high);
  merge(a, low, mid, high);
}

void merge(int a[], int low, int mid, int high){
  int p1 = low;
  int p2 = mid + 1;
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