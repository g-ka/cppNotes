#include <iostream>

class Stack{
  public:
  int top;
  int size;
  int min;
  std::pair<int, int>* arr;
  Stack(int size1){
    min = INT_MAX;
    top = -1;
    size = size1;
    arr = new std::pair<int, int>[size];
  }
  void push(int value){
    if(top==size-1){
      std::cout << "Stack overflow\n";
      return;
    }else{
      top++;
      if(value < min) min = value;
      arr[top] = {value, min};
    }    
  }
  void pop(){
    if(top==-1){
      std::cout << "Stack underflow\n";
      return;
    }else{
      top--;
    }
  }
  int Min(){
    if(top == -1){
      std::cout << "Stack underflow\n";
      exit(1);
    }else{
      return arr[top].second;
    }    
  }
  int Size(){
    return top+1;
  }
  int Top(){
    if(top==-1){
      std::cout << "Stack underflow\n";
      exit(1);
    }else{
      return arr[top].first;
    }
  }
  bool Empty(){
    return top == -1;
  }
};

int main(){

  Stack st(5);

  st.push(-1);  
  st.push(-2);
  st.push(5);
  st.push(-10);
  st.push(100);

  std::cout << st.Top() << "\n";
  std::cout << st.Size() << "\n";
  std::cout << st.Min() << "\n";
  st.pop();
  st.pop();  
  std::cout << st.Min() << "\n";

  return 0;
}