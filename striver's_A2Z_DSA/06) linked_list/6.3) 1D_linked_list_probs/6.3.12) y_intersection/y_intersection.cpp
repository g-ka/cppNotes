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
Node* intersectionAt(Node* head1, Node* head2);
int lengthOf(Node* head);

int main(){
  Node* head3 = nullptr;
  insertFirst(5, head3);
  insertFirst(4, head3);

  Node* head1 = nullptr;
  insertFirst(1, head1);
  insertFirst(2, head1);
  insertFirst(1, head1);
  head1->next->next->next = head3;

  Node* head2 = nullptr;
  insertFirst(3, head2);
  head2->next = head3;  

  for(Node* ptr=head1; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";
  std::cout << "\n";
  for(Node* ptr=head2; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  Node* intersectionPoint = intersectionAt(head1, head2);

  if(intersectionPoint!=nullptr) std::cout << "\n" << intersectionPoint->data;
  else std::cout << "\n" << "No intersection";

  return 0;
}

void insertFirst(int value, Node*& head){
  Node* currentNode = new Node(value);
  currentNode->next = head;
  head = currentNode;
}

Node* intersectionAt(Node* head1, Node* head2){
  int length1 = lengthOf(head1);
  int length2 = lengthOf(head2);
  Node* ptr1 = head1;
  Node* ptr2 = head2;
  if(length1>length2) for(int i=0; i<length1-length2; i++) ptr1 = ptr1->next;
  else for(int i=0; i<length2-length1; i++) ptr2 = ptr2->next;
  while(ptr1!=ptr2 && ptr1!=nullptr && ptr2!=nullptr){
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  return ptr1;
}

int lengthOf(Node* head){
  Node* slow = head;
  Node* fast = head;
  int slowLen = 1;
  int length = 0;
  while(fast!=nullptr && fast->next!=nullptr){
    slow = slow->next;
    fast = fast->next->next;
    slowLen++;
  }
  if(fast==nullptr) length = 2*slowLen - 2;
  else if(fast->next==nullptr) length = 2*slowLen - 1;
  return length; 
}