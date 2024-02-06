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
void reverseKGroup(Node*& head, int k);
std::pair<Node*, Node*> reverseK(Node*& ptr, Node* oldPtr, int k, bool isFirst);

int main(){

  Node* head = nullptr;
  insertFirst(10, head);
  insertFirst(9, head);
  insertFirst(8, head);
  insertFirst(7, head);
  insertFirst(6, head);
  insertFirst(5, head);
  insertFirst(4, head);
  insertFirst(3, head);
  insertFirst(2, head);
  insertFirst(1, head);

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  reverseKGroup(head, 3);

  std::cout << "\n";
  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  return 0;
}

void insertFirst(int value, Node*& head){
  Node* currentNode = new Node(value);
  currentNode->next = head;
  head = currentNode;
}

void reverseKGroup(Node*& head, int k){
  if(head==nullptr || head->next==nullptr || k==1) return;
  else{
    Node* slow = head;
    Node* fast = head;
    int slowPos =  1;
    while(fast!=nullptr && fast->next!=nullptr){
      slow = slow->next;
      fast = fast->next->next;
      slowPos++;
    }
    int length = 0;
    if(fast==nullptr) length = 2*slowPos - 2;
    else length = 2*slowPos - 1;
    int turns = length/k;
    std::pair<Node*, Node*> ptrs = reverseK(head, nullptr, k, true);
    turns--;
    while(turns){
      ptrs = reverseK(ptrs.second, ptrs.first, k, false);
      turns--;
    }
  }
}

std::pair<Node*, Node*> reverseK(Node*& ptr, Node* oldPtr, int k, bool isFirst){
  Node* start = ptr;
  Node* first = ptr;
  Node* middle = first->next;
  Node* last = middle->next;
  first->next = nullptr;
  while(k!=1){
    middle->next = first;
    first = middle;
    middle = last;
    if(last!=nullptr) last = last->next;
    k--;
  }
  start->next = middle;
  if(isFirst) ptr = first;
  if(!isFirst) oldPtr->next = first;
  return {start, middle};
}