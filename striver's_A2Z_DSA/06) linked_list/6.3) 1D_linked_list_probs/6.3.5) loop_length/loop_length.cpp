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
void createCycleAt(int value, Node* head);
int loopLength(Node* head);

int main(){

  Node* head = nullptr;
  insertFirst(50, head);
  insertFirst(40, head);
  insertFirst(30, head);
  insertFirst(20, head);
  insertFirst(10, head);  

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  createCycleAt(1, head);

  int loopLen = loopLength(head);

  if(loopLen) std::cout << "\n" << "Loop length: " << loopLen;
  else std::cout << "\n" << "No loop exist";

  return 0;
}

void insertFirst(int value, Node*& head){
  Node* currentNode = new Node(value);
  currentNode->next = head;
  head = currentNode;
}

void createCycleAt(int value, Node* head){
  Node* tempPtr = head;
  Node* indexPtr = nullptr;
  int index = 0;
  while(tempPtr->next!=nullptr){
    if(index == value) indexPtr = tempPtr;
    tempPtr = tempPtr->next;
    index++;
  }
  tempPtr->next = indexPtr;
}

int loopLength(Node* head){
  Node* ptr1 = head;
  Node* ptr2 = head;
  while(ptr2!=nullptr && ptr2->next!=nullptr){
    ptr1 = ptr1->next;
    ptr2 = ptr2->next->next;
    if(ptr1 == ptr2){
      ptr1 = ptr1->next;
      int length = 1;
      while(ptr1!=ptr2){
        ptr1 = ptr1->next;
        length++;
      }
      return length;
    };
  }
  return 0;
}