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

void reverseLL(Node*& head){
  if(head->next == nullptr) return;

  Node* ptr1 = head;
  head = head->next;
  Node* ptr2 = head->next;
  ptr1->next = nullptr;

  while(head->next!=nullptr){
    head->next = ptr1;
    ptr1 = head;
    head = ptr2;
    ptr2 = ptr2->next;
  }
  head->next = ptr1;
}

int main(){

  Node* head = nullptr;
  insertFirst(40, head);
  insertFirst(30, head);
  insertFirst(20, head);
  insertFirst(10, head);

  std::cout << "Original LL: ";
  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  reverseLL(head);

  std::cout << "\nReversed LL: ";
  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  return 0;
}