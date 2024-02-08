#include <iostream>
#include <bits/stdc++.h>

class Stack{
  public:
  int top;
  int size;
  int min;
  int* arr;
  Stack(int length){    
    top  = -1;
    size = length;
    min = INT_MAX;
    arr = new int [size];
  }
  void push(int value){
    if(top == size - 1){
      std::cout << "Stack overflow\n";
      return;
    }else if(top == -1){
      top++;
      arr[top] = value;
      min = value;
    }else{
      top++;
      if(value < min){        
        arr[top] = 2*value - min;    
        min = value;          
      }else{
        arr[top] = value;
      }
    }
  }
  void pop(){
    if(top == -1){
      std::cout << "Stack underflow\n";
      return;
    }else{
      if(arr[top] > min){
        top--;
      }else{
        min = 2*min - arr[top];
        top--;
      }
    }
  }
  int Min(){
    if(top == -1){
      std::cout << "Stack underflow\n";
      exit(1);
    }else{
      return min;
    }
  }
  int Size(){
    return top + 1;
  }
  int Top(){  
    if(top == -1){
      std::cout << "Stack underflow\n";
      exit(1);
    }
    else if(arr[top] < min){
      return min;
    }else{
      return arr[top];
    }
  }
  bool Empty(){
    return top == -1;
  }
};

int main(){

  Stack st(8);

  st.push(2);
  st.push(-1);
  st.push(0);
  st.push(-3);
  st.push(-2);
  st.push(-5);
  st.push(8);
  st.push(1);
  st.pop();
  st.pop();
  st.pop();
  st.pop();
  st.pop();
  st.pop();
  std::cout << "Top: " << st.Top() << "\n";
  std::cout << "Min: " << st.Min() << "\n";
  std::cout << "Size: " << st.Size() << "\n";

  return 0;
}