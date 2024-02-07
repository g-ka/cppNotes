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

class StackLL{
  public:
  Node* top;
  int size;
  StackLL(){
    top = nullptr;
    size = 0;
  }
  void push(int value){
    Node* currentNode = new Node(value);
    currentNode->next = top;
    top = currentNode;
    size++;
  }
  void pop(){
    if(top==nullptr){
      std::cout << "Stack underflow";      
    }else{
      Node* temp = top;
      top = top->next;
      delete temp;
      size--;
    }    
  }
  int Size(){
    return size;
  }
  int Top(){
    if(top==nullptr){
      std::cout << "Stack underflow";      
      exit(1);
    }else{
      return top->data;
    }
  }
  bool empty(){
    return top == nullptr;
  }
};

int main(){

  StackLL sll;
  sll.push(4);
  sll.push(3);    
  sll.pop();
  sll.pop();

  for(Node* ptr=sll.top; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";
  std::cout << "\n";
  std::cout << sll.Size() << "\n";
  std::cout << sll.empty() << "\n";
  std::cout << sll.Top() << "\n";   

  return 0;
}