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
Node* middlePosition(Node* head);

int main(){

  Node* head = nullptr;
  insertFirst(50, head);
  insertFirst(40, head);
  insertFirst(30, head);
  insertFirst(20, head);
  insertFirst(10, head);

  std::cout << "Original LinkedList: ";
  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  Node* middleNode = middlePosition(head);
  
  std::cout << "\nLinkedList from middle: ";
  for(Node* ptr=middleNode; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  return 0;
}

void insertFirst(int value, Node*& head){
  Node* currentNode = new Node(value);
  currentNode->next = head;
  head = currentNode;
}

Node* middlePosition(Node* head){
  Node *ptr1 = head, *ptr2 = head;
  bool isOdd = false;

  if(ptr1->next==nullptr) return ptr1;
  while(ptr2->next!=nullptr && ptr2->next->next!=nullptr){
    ptr1 = ptr1->next;
    ptr2 = ptr2->next->next;
    if(ptr2->next==nullptr) isOdd = true;
  }

  return (isOdd ? ptr1 : ptr1->next);
}