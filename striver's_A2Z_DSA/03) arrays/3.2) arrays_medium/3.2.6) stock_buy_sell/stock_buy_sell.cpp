#include <iostream>

void predict(int a[], int);

int main(){

  int numbers[] = {7,1,5,3,6,4};
  const int SIZE = sizeof(numbers)/sizeof(int);

  predict(numbers, SIZE);

  return 0;
}

void predict(int a[], const int SIZE){

  int buy = -1;
  int sell = -1;
  int maxProfit = 0;

  for(int i=0; i<SIZE-1; i++){
    for(int j=i+1; j<SIZE; j++){
      if(a[j] - a[i] > maxProfit){
        buy = i;
        sell = j;
        maxProfit = a[j] - a[i];
      }
    }
  }

  if(maxProfit) std::cout << "Buy on day " << buy+1 << " and sell on day " << sell+1 << " for a profit of " << maxProfit << " units";
  else std::cout << "No profit could be made";

}