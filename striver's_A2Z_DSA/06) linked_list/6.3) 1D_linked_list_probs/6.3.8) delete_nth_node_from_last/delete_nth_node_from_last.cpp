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
void deleteNthNodeFromLast(int index, Node* head);
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

  deleteNthNodeFromLast(3, head);

  std::cout << "\nAfter deletion: ";
  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  return 0;
}

void insertFirst(int value, Node*& head){
  Node* currentNode = new Node(value);
  currentNode->next = head;
  head = currentNode;
}

void deleteNthNodeFromLast(int pos, Node* head){
  Node* slow = head;
  Node* fast = head;
  int slowPos = 1;
  while(fast!=nullptr && fast->next!=nullptr){
    slow = slow->next;
    fast = fast->next->next;
    slowPos++;
  }

  if(pos == 1){
    if(head->next==nullptr) head = nullptr;
    Node* temp = head;
    while(temp->next->next != nullptr) temp = temp->next;
    temp->next = nullptr;
  }else{
    int length = 1;
    if(fast==nullptr) length = 2*slowPos - 2;
    else if(fast->next==nullptr) length = 2*slowPos - 1;

    int delNodePos = length - pos + 1;

    if(delNodePos>=slowPos){
      while(slowPos!=delNodePos){
        slow = slow->next;
        slowPos++;
      }
      deleteNode(slow);
    }
    else{
      int tempPos = 1;
      Node* temp = head;
      while(tempPos!=delNodePos){
        temp = temp->next;
        tempPos++;
      }
      deleteNode(temp);
    }    
  }
}

void deleteNode(Node* ptr){
  Node* temp1 = ptr->next;
  Node* temp2 = temp1->next;
  ptr->data = temp1->data;
  temp1->next = nullptr;
  ptr->next = temp2;
}