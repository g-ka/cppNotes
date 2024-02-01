#include <iostream>

class Node{
  public:
  int data;
  Node* next;
  Node(){
    data = NULL;
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

void insertAtFirst(int value, Node*& head){
  Node* currentNode = new Node(value);
  currentNode->next = head;
  head = currentNode;
}

void deleteLast(Node* head){
  Node* ptr = head;
  while(ptr->next->next!=nullptr){
    ptr = ptr->next;
  }
  delete ptr->next;
  ptr->next = nullptr;
}

int main(){

  Node* head = nullptr;
  insertAtFirst(40, head);
  insertAtFirst(30, head);
  insertAtFirst(20, head);
  insertAtFirst(10, head);

  std::cout << "before deletion: ";
  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next){
    std::cout << ptr->data << " ";
  }

  deleteLast(head);

  std::cout << "\nafter deletion: ";
  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next){
    std::cout << ptr->data << " ";
  }

  return 0;
}