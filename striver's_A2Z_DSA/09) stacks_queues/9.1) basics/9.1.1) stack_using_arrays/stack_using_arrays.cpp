#include <iostream>

class Stack{
  public:
  int top ;
  int size;
  int* arr;
  Stack(){
    top = -1;
    size = 5;
    arr = new int[size];
  }
  void push(int value){
    if(top+1==size){
      std::cout << "Stack ovreflow\n";
      return;
    }
    top++;
    arr[top] = value;
  }
  void pop(){
    if(top==-1){
      std::cout << "Stack underflow\n";
      return;
    }
    top--;
  }
  int Top(){
    return arr[top];
  }
  int Size(){
    return top+1;
  }
  bool empty(){
    if(top==-1) return true;
    else return false;
  }
};

int main(){

  Stack s;
  s.pop();
  s.push(1);
  s.push(3);
  s.push(3);
  s.push(3);
  s.push(8);
  s.push(8);
  std::cout << s.Size() << "\n";

  return 0;
}