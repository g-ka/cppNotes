#include <iostream>

class Node{
  public:
  int data;
  Node* next;
  Node* random;
  Node(){
    data = 0;
    next = nullptr;
    random = nullptr;
  }
  Node(int value){
    data = value;
    next = nullptr;
    random = nullptr;
  }
  Node(int value, Node* ptr1, Node* ptr2){
    data = value;
    next = ptr1;
    random = ptr2;
  }
};

void insertFirst(int value, Node*& head);
Node* clone(Node* head);

int main(){

  Node* head = nullptr;
  insertFirst(1, head);
  insertFirst(10, head);
  insertFirst(11, head);
  insertFirst(13, head);
  insertFirst(7, head);

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  Node* headClone = clone(head);

  std::cout << "\n";
  for(Node* ptr=headClone; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  return 0;
}

void insertFirst(int value, Node*& head){
  Node* currentNode = new Node(value);
  currentNode->next = head;
  head = currentNode;
}

Node* clone(Node* head){
  if(head==nullptr) return nullptr;

  Node* ptr = head;
  while(ptr!=nullptr){
    Node* cloneNode = new Node(ptr->data);
    cloneNode->next = ptr->next;
    ptr->next = cloneNode;
    ptr = ptr->next->next;
  }

  ptr = head;
  while(ptr!=nullptr){
    if(ptr->random==nullptr) ptr->next->random = nullptr;
    else ptr->next->random = ptr->random->next;
    ptr = ptr->next->next;
  }

  Node* headC = head->next;
  Node* ptrC = headC;
  ptr = head;
  while(ptr!=nullptr){
    ptr->next = ptr->next->next;
    if(ptrC->next!=nullptr) ptrC->next = ptrC->next->next;
    ptr = ptr->next;
    ptrC = ptrC->next;
  }
  
  return headC;
}