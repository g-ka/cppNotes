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
void removeDuplicates(Node*& head);
void deleteNode(Node*& ptr);

int main(){

  Node* head = nullptr;
  Node* tail = nullptr;
  insertLast(1, head, tail);
  insertLast(2, head, tail);
  insertLast(2, head, tail);
  insertLast(3, head, tail);
  insertLast(3, head, tail);
  insertLast(4, head, tail);
  insertLast(4, head, tail);

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  removeDuplicates(head);

  std::cout << "\n";
  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

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

void removeDuplicates(Node*& head){
  Node* ptr = head;
  int prevVal = 0;    
  while(ptr!=nullptr){
      if(ptr->data==prevVal) deleteNode(ptr);
      else {
        prevVal = ptr->data;
        ptr = ptr->next;
      }
  }
}

void deleteNode(Node*& ptr){
  Node* ptr1 = ptr->next;
  if (ptr->next == nullptr && ptr->back == nullptr) {
    ptr = nullptr;
    return;
  }
  if(ptr->next==nullptr){
      ptr->back->next = nullptr;
      ptr->back = nullptr;
      return;
  }else if(ptr->next->next==nullptr){
      ptr->data = ptr1->data;
      ptr->next = nullptr;    
  }else{
      ptr->data = ptr1->data;
      ptr->next = ptr1->next;
      ptr1->next->back = ptr;
  }
  ptr1->next = nullptr;
  ptr1->back = nullptr;
}