#include <iostream>

class Node{
  public:
  int data;
  Node* next;
  Node(){
    data = 0;
    next = nullptr;
  }
  Node(int data1){
    data = data1;
    next = nullptr;
  }
  Node(int data1, Node* next1){
    data = data1;
    next = next1;
  }
};

Node* insertAtFirst(int value, Node* head){
  Node* currentNode = new Node(value);
  currentNode->next = head;
  head = currentNode;  
  return head;
}

void printLL(Node* head){
  for(Node* pointer=head; pointer!=nullptr; pointer=pointer->next){
    std::cout << pointer->data << " ";
  }
}

int main(){

  Node* head = nullptr;
  head = insertAtFirst(40, head);
  head = insertAtFirst(30, head);
  head = insertAtFirst(20, head);
  head = insertAtFirst(10, head);

  printLL(head);

  return 0;
}