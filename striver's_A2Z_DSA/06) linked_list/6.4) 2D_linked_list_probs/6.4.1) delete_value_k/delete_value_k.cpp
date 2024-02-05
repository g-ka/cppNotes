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
void deleteK(Node*& head, int k);

int main(){

  Node* head = nullptr;
  Node* tail = nullptr;
  insertLast(10, head, tail);
  insertLast(4, head, tail);
  insertLast(10, head, tail);
  insertLast(3, head, tail);
  insertLast(5, head, tail);
  insertLast(20, head, tail);
  insertLast(10, head, tail);

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  deleteK(head, 10);

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

void deleteK(Node*& head, int k){
  Node* ptr = head;
  while(ptr!=nullptr){
    if(ptr->data==k){
      Node* ptr1 = ptr->next;
      if(head->next==nullptr && head->back==nullptr) head = nullptr;
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
    ptr = ptr->next;
  }
}