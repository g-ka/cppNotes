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
    next = nullptr;
  }
};

void insertFirst(int value, Node*& head);
bool isPalindrome(Node* head);

int main(){

  Node* head = nullptr;
  insertFirst(10, head);
  insertFirst(20, head);
  insertFirst(30, head);
  insertFirst(40, head);
  insertFirst(30, head);
  insertFirst(20, head);
  insertFirst(10, head);

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  bool result = isPalindrome(head);

  std::cout << "\n" << (result ? "Its a palindrome" : "Its not a palindrome");

  return 0;
}

void insertFirst(int value, Node*& head){
  Node* currentNode = new Node(value);
  currentNode->next = head;
  head = currentNode;
}

bool isPalindrome(Node* head){
  if(head->next==nullptr) return true;

  Node* p1 = head;
  head = head->next;
  Node* p2 = head->next;
  Node* fast =  p2;
  bool isEven = true;
  p1->next = nullptr;

  while(fast!=nullptr && fast->next!=nullptr){
    head->next = p1;
    p1 = head;
    head = p2;
    p2 = p2->next;
    fast = fast->next->next;
  }

  if(fast->next==nullptr) isEven = false;  

  if(isEven){
    while(head!=nullptr){
      if(head->data != p1->data) return false;
      head = head->next;
      p1 = p1->next;
    }
    return true;
  }else{
    while(p2!=nullptr){
      if(p2->data != p1->data) return false;
      p2 = p2->next;
      p1 = p1->next;
    }
    return true;
  }
}