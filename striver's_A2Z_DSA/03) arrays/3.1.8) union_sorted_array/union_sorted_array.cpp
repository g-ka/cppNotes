#include <iostream>

void ouputUnionOf(int a[], int b[], int, int);

int main(){

  int numbers1[] = {1,2,3,4,5,6,7,8,9,10};
  int numbers2[] = {2,3,4,4,5,11,12};
  const int SIZE1 = sizeof(numbers1)/sizeof(int);
  const int SIZE2 = sizeof(numbers2)/sizeof(int);

  ouputUnionOf(numbers1, numbers2, SIZE1, SIZE2);

  return 0;
}

void ouputUnionOf(int a[], int b[], const int S1, const int S2){

  int unionArray[S1+S2];
  int index = 0;
  int aPoint = 0;
  int bPoint = 0;
  // int count = 0;

  while(aPoint < S1 && bPoint < S2){
    // count++;
    if(a[aPoint] == b[bPoint]){
      if(unionArray[index-1] != a[aPoint]){
        unionArray[index] = a[aPoint];
        index++;
      }      
      aPoint++;
      bPoint++;
    }else if(a[aPoint] < b[bPoint]){
      if(unionArray[index-1] != a[aPoint]){
        unionArray[index] = a[aPoint];
        index++;
      }
      aPoint++;
    }else{
      if(unionArray[index-1] != b[bPoint]){
        unionArray[index] = b[bPoint];
        index++;
      }
      bPoint++;
    }
  }

  if(aPoint == S1){
    for(int i=bPoint; i<S2; i++){
      // count++;
      if(unionArray[index-1] != b[i]){
        unionArray[index] = b[i];
        index++;
      }      
    }
  }else{
    for(int i=aPoint; i<S1; i++){
      // count++;
      if(unionArray[index-1] != a[i]){
        unionArray[index] = a[i];
        index++;
      }      
    }
  }

  // std::cout << "count: " << count << "\n";
  for(int i=0; i<index; i++){
    std::cout << unionArray[i] << " ";
  }
}