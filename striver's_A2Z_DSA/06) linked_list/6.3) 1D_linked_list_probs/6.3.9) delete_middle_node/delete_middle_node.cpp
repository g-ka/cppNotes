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
void deleteNthNodeFromLast(Node* head);
void deleteNode(Node* ptr);

int main(){

  Node* head = nullptr;  
  insertFirst(60, head);
  insertFirst(50, head);
  insertFirst(40, head);
  insertFirst(30, head);
  insertFirst(20, head);
  insertFirst(10, head);

  std::cout << "Original linked list: ";
  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  deleteNthNodeFromLast(head);

  std::cout << "\nAfter deletion: ";
  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  return 0;
}

void insertFirst(int value, Node*& head){
  Node* currentNode = new Node(value);
  currentNode->next = head;
  head = currentNode;
}

void deleteNthNodeFromLast(Node* head){
  if(head->next==nullptr){
    head = nullptr;
    return;
  }
  if(head->next->next==nullptr){
    head->next = nullptr;
    return;
  }
  Node* slow = head;
  Node* fast = head;
  while(fast!=nullptr && fast->next!=nullptr){
    slow = slow->next;
    fast = fast->next->next;
  }
  deleteNode(slow);
}

void deleteNode(Node* ptr){
  Node* temp1 = ptr->next;
  Node* temp2 = temp1->next;
  ptr->data = temp1->data;
  temp1->next = nullptr;
  ptr->next = temp2;
}