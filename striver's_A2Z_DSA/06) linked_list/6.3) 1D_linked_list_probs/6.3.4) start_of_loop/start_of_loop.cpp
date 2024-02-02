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
Node* cycleStartAt(Node* head);

int main(){

  Node* head = nullptr;
  insertFirst(50, head);
  insertFirst(40, head);
  insertFirst(30, head); 
  insertFirst(20, head); 
  insertFirst(10, head); 

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  Node* startIndex = cycleStartAt(head);

  std::cout << "\n";
  if(startIndex==nullptr) std::cout << "NO LOOP";
  else std::cout << startIndex;

  return 0;
}

void insertFirst(int value, Node*& head){
  Node* currentNode = new Node(value);
  currentNode->next = head;
  head = currentNode;
}

Node* cycleStartAt(Node* head){
  Node* ptr1 = head;
  Node* ptr2 = head;
  while(ptr2!=nullptr && ptr2->next!=nullptr){
      ptr1 = ptr1->next;            
      ptr2 = ptr2->next->next;        
      if (ptr1 == ptr2){
          Node* indexPtr = head;                
          while(indexPtr != ptr1){
          indexPtr = indexPtr->next;
          ptr1 = ptr1->next;
          }
          return indexPtr; 
      }            
  }
  return nullptr;
}