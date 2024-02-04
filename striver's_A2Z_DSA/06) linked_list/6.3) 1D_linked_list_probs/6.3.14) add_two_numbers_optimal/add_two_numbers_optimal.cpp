#include <iostream>
#include <bits/stdc++.h>

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
Node* add2LL(Node* head1, Node* head2);

int main(){

  Node* head1 = nullptr;
  insertFirst(9, head1);
  insertFirst(9, head1);
  insertFirst(9, head1);
  insertFirst(9, head1);
  insertFirst(9, head1);
  insertFirst(9, head1);
  insertFirst(9, head1);

  Node* head2 = nullptr;
  insertFirst(9, head2);
  insertFirst(9, head2);
  insertFirst(9, head2);
  insertFirst(9, head2);

  for(Node* ptr=head1; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";
  std::cout << "\n";
  for(Node* ptr=head2; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  Node* head = add2LL(head1, head2);

  std::cout << "\n";
  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  return 0;
}

void insertFirst(int value, Node*& head){
  Node* currentNode = new Node(value);
  currentNode->next = head;
  head = currentNode;
}

Node* add2LL(Node* head1, Node* head2){
  Node* ptr1 = head1;
  Node* ptr2 = head2;
  int remainder = 0;
  Node* head = nullptr;
  Node* temp = nullptr;

  while(ptr1!=nullptr && ptr2!=nullptr){
    int num = ptr1->data + ptr2->data + remainder;
    remainder = num/10;  
    Node* currentNode = new Node(num%10);
    if(temp==nullptr){
      temp = currentNode;
      head = temp;
    }
    else{
      temp->next = currentNode;
      temp = currentNode;
    }
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  while(ptr1!=nullptr){
    int num = ptr1->data + remainder;
    remainder = num/10;   
    Node* currentNode = new Node(num%10);
    temp->next = currentNode;
    temp = currentNode;
    ptr1 = ptr1->next;
  }
  while(ptr2!=nullptr){
    int num = ptr2->data + remainder;
    remainder = num/10;
    Node* currentNode = new Node(num%10);
    temp->next = currentNode;
    temp = currentNode;
    ptr2 = ptr2->next;
  }

  if(remainder!=0){
    Node* currentNode = new Node(remainder);
    temp->next = currentNode;
    temp = currentNode;
  }

  return head;
}