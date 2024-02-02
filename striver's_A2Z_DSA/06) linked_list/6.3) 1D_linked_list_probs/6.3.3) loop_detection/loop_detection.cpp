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
bool isLoop(Node* head);

int main(){

  Node* head = nullptr;
  insertFirst(70, head);
  insertFirst(60, head);
  insertFirst(50, head);
  insertFirst(40, head);
  insertFirst(30, head); 
  insertFirst(20, head); 
  insertFirst(10, head); 

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  bool loopExist = isLoop(head);

  std::cout << "\n" << loopExist;

  return 0;
}

void insertFirst(int value, Node*& head){
  Node* currentNode = new Node(value);
  currentNode->next = head;
  head = currentNode;
}

bool isLoop(Node* head){
  Node* ptr1 = head;
  Node* ptr2 = head;  
  while(ptr2->next!=nullptr && ptr2!=nullptr){
      ptr1 = ptr1->next;
      ptr2 = ptr2->next->next;
      if(ptr1==ptr2) return true;
  }
  return false;
}