#include <iostream>

class Queue{
  public:
  int front;
  int last;
  int size;
  int* arr;
  Queue(){
    front = -1;
    last = -1;
    size = 5;
    arr = new int[size];
  }
  void push(int value){
    if(last+1==size){
      std::cout << "Queue is full\n";
      return;
    }
    if(front==-1){
      last++;
      arr[last] = value;
      front++;
    }else{
      last++;
      arr[last] = value;
    }
  }
  void pop(){
    if(front==last && front==-1) std::cout << "Queue is empty\n";
    if(front==last && front==0){
      front = -1;
      last = -1;
    }else{
      for(int i=front; i<last; i++) arr[i] = arr[i+1];
      last--;
    }
  }
  int Front(){
    if(front==-1){
      std::cout << "Code exit(1) as Queue is empty";
      exit(1);
    }
    return arr[front];
  }
  int Last(){
    if(last==-1){
      std::cout << "Code exit(1) as Queue is empty";
      exit(1);
    }
    return arr[last];
  }
  int Size(){
    return last+1;
  }
  bool empty(){
    if(front==-1) return true;
    else return false;
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
  q.pop();
  std::cout << q.Front() << "\n";
  std::cout << q.Last() << "\n";

  return 0;
}