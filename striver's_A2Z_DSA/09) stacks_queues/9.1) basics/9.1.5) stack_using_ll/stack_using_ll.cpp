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
  Node* head;
  StackLL(){
    head = nullptr;
  }
  void push(int value){
    Node* currentNode = new Node(value);
    currentNode->next = head;
    head = currentNode;
  }
  void pop(){
    if(head==nullptr){
      std::cout << "Stack underflow";
      return;
    }
    Node* temp = head->next;
    head->next = nullptr;
    head = temp;
  }
  int Size(){
    if(head==nullptr) return 0;
    else if(head->next==nullptr) return 1;
    Node* slow = head;
    Node* fast = head;
    int slowPos = 1;
    while(fast!=nullptr && fast->next!=nullptr){
      slow = slow->next;
      fast = fast->next->next;
      slowPos++;
    }
    int length = 0;
    if(fast==nullptr) length = 2*slowPos - 2;
    else length = 2*slowPos - 1;
    return length;
  }
  int Top(){
    if(head==nullptr){
      std::cout << "Stack underflow";
      exit(1);
    }
    return head->data;
  }
  bool empty(){
    if(head==nullptr) return true;
    else return false;
  }
};

int main(){

  StackLL sll;
  sll.push(4);
  sll.push(3);    
  sll.pop();
  sll.pop();

  for(Node* ptr=sll.head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";
  std::cout << "\n";
  std::cout << sll.Size() << "\n";
  std::cout << sll.empty() << "\n";
  std::cout << sll.Top() << "\n";   

  return 0;
}