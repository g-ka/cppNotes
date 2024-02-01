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

int elementNum(Node* head){
  Node* tempPtr = head;
  int count = 1;
  while(tempPtr->next!=nullptr){
    tempPtr = tempPtr->next;
    count++;
  }
  return count;
}

int main(){

  Node* head = nullptr;
  insertFirst(40, head);
  insertFirst(30, head);
  insertFirst(20, head);
  insertFirst(10, head);

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  int count = elementNum(head);

  std::cout << "\n" << "The number of elements: " << count;

  return 0;
}