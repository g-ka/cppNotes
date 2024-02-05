#include <iostream>

class Node{
  public:
  int data;
  Node* next;
  Node* back;
  Node(){
    data = 0;
    next = nullptr;
    back = nullptr;
  }
  Node(int value){
    data = value;
    next = nullptr;
    back = nullptr;
  }
  Node(int value, Node* ptr1, Node* ptr2){
    data = value;
    next = ptr1;
    back = ptr2;
  }
};

void insertFirst(int value, Node*& head, Node*& tail);

int main(){

  Node* head = nullptr;
  Node* tail = nullptr; 
  insertFirst(4, head, tail);
  insertFirst(3, head, tail);
  insertFirst(2, head, tail);
  insertFirst(1, head, tail);   

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";
  std::cout << "\n";
  for(Node* ptr=tail; ptr!=nullptr; ptr=ptr->back) std::cout << ptr->data << " ";

  return 0;
}

void insertFirst(int value, Node*& head, Node*& tail){
  Node* currentNode = new Node(value);
  if(tail==nullptr){
    head = currentNode;
    tail = currentNode;
  }else{
    head->back = currentNode; 
    currentNode->next = head;     
    head = currentNode;
  }
}