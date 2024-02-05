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
void rotate(Node*& head, int k);

int main(){

  Node* head = nullptr;
  insertFirst(5, head);
  insertFirst(4, head);
  insertFirst(3, head);
  insertFirst(2, head);
  insertFirst(1, head);

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  rotate(head, 2);

  std::cout << "\n";
  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  return 0;
}

void insertFirst(int value, Node*& head){
  Node* currentNode = new Node(value);
  currentNode->next = head;
  head = currentNode;
}

void rotate(Node*& head, int k){
  if(head==nullptr || head->next==nullptr || k==0) return head;
  Node* slow = head;
  Node* fast = head;
  int slowPos = 1;
  while(fast!=nullptr && fast->next!=nullptr){
    slow = slow->next;
    fast = fast->next->next;
    slowPos++;
  }
  int length = 0;
  if(fast==nullptr) length = 2*slowPos - 2;
  else length = 2*slowPos - 1;

  k %= length;
  k = length - k;

  if(k!=length){
    Node* prevHead = nullptr;
    Node* start = head;
    Node* ptr = head;
    while(ptr->next!=nullptr){
      if(k!=0){        
        prevHead = head;
        head = head->next;
        k--;
      }
      ptr = ptr->next;
    }
    ptr->next = start;
    prevHead->next = nullptr;
  }  
}