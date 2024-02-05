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
void reverse(Node*& head);

int main(){

  Node* head = nullptr;
  Node* tail = nullptr;
  insertLast(1, head, tail);
  insertLast(2, head, tail);
  insertLast(3, head, tail);
  insertLast(4, head, tail);

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  reverse(head);

  std::cout << "\n";
  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  return 0;
}

void insertLast(int value, Node*& head, Node*& tail){
  Node* currentNode = new Node(value);
  if(head==nullptr){
    head = currentNode;
    tail = currentNode;
  }else{
    tail->next = currentNode;
    currentNode->back = tail;
    tail = currentNode;
  }
}

void reverse(Node*& head){
  if(head==nullptr || head->next==nullptr) return head;
  else{
    Node* finalHead = nullptr;
    while(head!=nullptr){
      Node* ptr1 = head->back;
      Node* ptr2 = head->next;
      head->next = ptr1;
      head->back = ptr2;    
      if(head->back==nullptr) finalHead = head;
      head = head->back;
    }
    head = finalHead;
  }  
}