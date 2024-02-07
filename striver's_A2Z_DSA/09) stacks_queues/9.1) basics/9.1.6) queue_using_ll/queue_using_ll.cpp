#include <iostream>

class Node{
  public:
  int data;
  Node* next;
  Node(){
    data = 0;
    next = nullptr;
  }
  Node(int value){
    data = value;
    next = nullptr;
  }
  Node(int value, Node* ptr){
    data = value;
    next = ptr;
  }
};

class QueueLL{
  public:
  Node* front;
  Node* rear;
  int size;
  QueueLL(){
    front = nullptr;
    rear = nullptr;
    size = 0;
  }
  void push(int value){
    Node* newNode = new Node(value);
    if(front == nullptr){
      front = newNode;
      rear = newNode;
    }else{
      rear->next = newNode;
      rear = newNode;
    }
    size++;
  }
  void pop(){
    if(front == nullptr){
      std::cout << "Queue is empty";
      return;
    }else{
      if(front == rear){
        front = nullptr;
        rear = nullptr;
      }else{
        Node* temp = front->next;
        front->next = nullptr;
        front = temp;
      }
      size--;
    }
  }
  int Top(){
    if(front == nullptr){
      std::cout << "Queue is empty";
      exit(1);
    }else return front->data;
  }
  int Size(){
    return size;
  }
  bool empty(){
    if(front == nullptr) return true;
    else return false;
  }
};

int main(){

  QueueLL qll;
  std::cout << qll.empty() << "\n";
  qll.push(1);
  qll.push(2);
  std::cout << qll.Top() << "\n";
  std::cout << qll.Size() << "\n";
  qll.pop();
  std::cout << qll.Top() << "\n";
  
  return 0;
}