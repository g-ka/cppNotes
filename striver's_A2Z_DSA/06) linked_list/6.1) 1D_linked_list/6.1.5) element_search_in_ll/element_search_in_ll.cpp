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

void insertFirst(int value, Node*& head){
  Node* currentNode = new Node(value);
  currentNode->next = head;
  head = currentNode;
}

int searchElement(int value , Node* head){
  Node* tempPtr = head;
  int position = 1;
  if(tempPtr->data == value) return position;
  while(tempPtr->next!=nullptr){
    if(tempPtr->data == value) return position;
    tempPtr = tempPtr->next;
    position++;    
  }
  if(tempPtr->data == value) return position;
  return -1;
}

int main(){

  Node* head = nullptr;
  insertFirst(40, head);
  insertFirst(30, head);
  insertFirst(20, head);
  insertFirst(10, head);

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  int position = searchElement(40, head);

  std::cout << "\n" << position;

  return 0;
}