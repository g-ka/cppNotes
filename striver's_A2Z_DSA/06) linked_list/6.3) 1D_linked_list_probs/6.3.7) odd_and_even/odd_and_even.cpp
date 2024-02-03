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
void alterOddEven(Node* head);

int main(){

  Node* head = nullptr;
  insertFirst(6, head);
  insertFirst(5, head);
  insertFirst(4, head);
  insertFirst(3, head);
  insertFirst(2, head);
  insertFirst(1, head);

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  alterOddEven(head);

  std::cout << "\nAltered LinkedList: ";
  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  return 0;
}

void insertFirst(int value, Node*& head){
  Node* currentNode = new Node(value);
  currentNode->next = head;
  head = currentNode;
}

void alterOddEven(Node* head){
  if(head==nullptr || head->next==nullptr || head->next->next==nullptr) return;
  
  Node* temp = nullptr;
  if(head->next->next->next == nullptr) temp = head->next;  
  Node* lo = head;
  Node* no = head->next->next;
  Node* p1 = nullptr;
  Node* p2 = nullptr;

  if(no != nullptr) p1 = no->next;
  if(p1 != nullptr) p2 = p1->next;

  while(no!=nullptr){
    if(p1 == nullptr){
      no->next = lo->next;
      lo->next = no;
      break;
    }
    int tempData = no->data;
    no->data = p1->data;
    p1->data = tempData;
    
    no->next = p2;
    p1->next = lo->next;
    lo->next = p1;
    lo = lo->next;
    temp = no;
    no = no->next;

    if(no != nullptr) p1 = no->next;
    else p1 = nullptr;

    if(p1 != nullptr) p2 = p1->next;
    else p2 = nullptr;
  }
  temp->next = nullptr;
}