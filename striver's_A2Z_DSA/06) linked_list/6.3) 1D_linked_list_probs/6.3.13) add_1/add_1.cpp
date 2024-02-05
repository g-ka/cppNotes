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

void insertFirst(int value, Node*& head);
void add1(Node*& head);

int main(){

  Node* head = nullptr;
  insertFirst(8, head);
  insertFirst(9, head);
  insertFirst(9, head);
  insertFirst(9, head);
  insertFirst(2, head);
  insertFirst(1, head);

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  add1(head);

  std::cout << "\n";
  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  return 0;
}

void insertFirst(int value, Node*& head){
  Node* currentNode = new Node(value);
  currentNode->next = head;
  head = currentNode;
}

void add1(Node*& head){
  Node* ptr = head;
  Node* start = nullptr;  
  while(ptr!=nullptr){
    if(ptr->data==9 && start==nullptr) start = ptr;
    else if(ptr->data != 9) start = nullptr;
    ptr = ptr->next;
  }
  if(start == head){ 
    insertFirst(1, head);
    while(start!=nullptr){
      start->data = 0;
      start = start->next;
    }
  }else if(start == nullptr){
    Node* tempPtr = head;
    while(tempPtr!=nullptr){
      if(tempPtr->next==nullptr) tempPtr->data += 1;
      tempPtr = tempPtr->next;
    }
  }else{
    Node* tempPtr = head;
    while(tempPtr!=start){
      if(tempPtr->next == start) tempPtr->data += 1;
      tempPtr = tempPtr->next;
    }
    while(start!=nullptr){
      start->data = 0;
      start = start->next;
    }
  }
}