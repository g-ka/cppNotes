#include <iostream>

class Queue{
  public:
  int front;
  int rear;
  int currentSize;
  int maxSize;
  int* arr;
  Queue(){
    front = 1;
    rear = 1;
    currentSize = 0;
    maxSize = 5;
    arr = new int[maxSize];
  }
  void push(int value){
    if(currentSize == maxSize){
      std::cout << "Queue is full\n";
      return;
    }else{      
      arr[rear%maxSize] = value;
      rear++;
      currentSize++;
    }
  }
  void pop(){
    if(currentSize == 0){
      std::cout << "Queue is empty\n";
      return;
    }else{
      arr[front%maxSize] = -1; // filler integer assuming the queue is only of non-negative integers
      front++;
      currentSize--;
    }
  }
  int Front(){
    if(currentSize == 0){
      std::cout << "Queue is empty\n";
      exit(1);
    }else{
      return arr[front%maxSize];
    }
  }
  int Rear(){
    if(currentSize == 0){
      std::cout << "Queue is empty\n";
      exit(1);
    }else{      
      return arr[(rear - 1)%maxSize];
    }
  }
  int Size(){
    return currentSize;
  }
  bool empty(){
    return currentSize == 0;
  }
};

int main(){

  Queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  q.pop();
  q.pop();
  q.pop();
  q.pop();
  q.pop();  
  q.push(1);
  q.push(2);
  q.push(12);
  std::cout << q.Front() << "\n";
  std::cout << q.Rear() << "\n";

  return 0;
}