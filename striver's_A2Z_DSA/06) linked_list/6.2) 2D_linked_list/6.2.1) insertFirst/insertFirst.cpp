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

void insertFirst(int value, Node*& head);

int main(){

  Node* head = nullptr;
  insertFirst(4, head);
  insertFirst(3, head);
  insertFirst(2, head);
  insertFirst(1, head);

  Node* tail = nullptr;

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next){
    std::cout << ptr->data << " ";
    if(ptr->next==nullptr) tail = ptr;
  }

  std::cout << "\n";
  for(Node* ptr=tail; ptr!=nullptr; ptr=ptr->back) std::cout << ptr->data << " ";

  return 0;
}

void insertFirst(int value, Node*& head){
  Node* currentNode = new Node(value);
  currentNode->next = head;
  if(head!=nullptr) head->back = currentNode;  
  head = currentNode;
}