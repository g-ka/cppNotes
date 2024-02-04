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
  insertFirst(6, head1);
  insertFirst(5, head1);

  Node* head2 = nullptr;
  insertFirst(9, head2);
  insertFirst(4, head2);
  insertFirst(5, head2);

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
  int sum = 0;
  int power = 0;

  while(ptr1!=nullptr && ptr2!=nullptr){
    sum += ((ptr1->data) + (ptr2->data))*pow(10, power);
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
    power++;
  }

  while(ptr1!=nullptr){
    sum += (ptr1->data)*pow(10, power);
    ptr1 = ptr1->next;
    power++;
  }
  while(ptr2!=nullptr){
    sum += (ptr2->data)*pow(10, power);
    ptr2 = ptr2->next;
    power++;
  }

  std::vector<int> revNum;
  if(sum==0) revNum.push_back(sum);
  else{
    while(sum!=0){        
      revNum.push_back(sum%10);
      sum /= 10;
    }
  }  

  Node* head = nullptr;  
  for(int i=revNum.size()-1; i>=0; i--) insertFirst(revNum[i], head);
  
  return head;
}