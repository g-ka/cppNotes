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

void insertLast(int value, Node*& head, Node*& tail);
void deleteLast(Node*& head, Node*& tail);

int main(){

  Node* head = nullptr;
  Node* tail = nullptr;
  insertLast(1, head, tail);
  insertLast(2, head, tail);
  insertLast(3, head, tail);
  insertLast(4, head, tail);

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";
  std::cout << "\n";
  for(Node* ptr=tail; ptr!=nullptr; ptr=ptr->back) std::cout << ptr->data << " ";
  std::cout << "\n";

  deleteLast(head, tail);

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";
  std::cout << "\n";
  for(Node* ptr=tail; ptr!=nullptr; ptr=ptr->back) std::cout << ptr->data << " ";  

  return 0;
}

void insertLast(int value, Node*& head, Node*& tail){
  Node* currentNode = new Node(value);
  if(head == nullptr){
    head = currentNode;
    tail = currentNode;
  }else{
    tail->next = currentNode;
    currentNode->back = tail;
    tail = currentNode;
  }  
}

void deleteLast(Node*& head, Node*& tail){
  if(head==nullptr) return;
  else if(head->next==nullptr){
      head = nullptr;
      tail = nullptr;
  }else{
      Node* ptr = tail->back;
      tail->back->next = nullptr;
      tail->back = nullptr;
      tail = ptr;
      ptr = nullptr;
  }
}