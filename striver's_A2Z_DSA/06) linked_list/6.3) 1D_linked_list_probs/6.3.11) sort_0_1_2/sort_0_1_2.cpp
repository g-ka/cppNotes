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
void sort012(Node* head);

int main(){
  Node* head = nullptr;
  insertFirst(0, head);
  insertFirst(2, head);
  insertFirst(2, head);
  insertFirst(0, head);
  insertFirst(1, head);
  insertFirst(1, head);
  insertFirst(2, head);
  insertFirst(0, head);
  insertFirst(2, head);
  insertFirst(0, head);
  insertFirst(1, head);
  insertFirst(1, head);
  insertFirst(0, head);
  insertFirst(1, head);
  insertFirst(0, head);
  insertFirst(0, head);
  insertFirst(1, head); 
  insertFirst(2, head); 
  insertFirst(2, head); 
  insertFirst(0, head); 

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  sort012(head);

  std::cout << "\n";
  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  return 0;
}

void insertFirst(int value, Node*& head){
  Node* currentNode = new Node(value);
  currentNode->next = head;
  head = currentNode;
}

void sort012(Node* head){
  Node* ptr1 = nullptr;
  Node* ptr2 = nullptr;

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next){
    if(ptr->data==1 && ptr1==nullptr && ptr2==nullptr) ptr1 = ptr;
    if(ptr->data==2 && ptr2==nullptr) ptr2 = ptr;

    if(ptr->data==0 && ptr1!=nullptr && ptr2!=nullptr){
      ptr1->data = 0;
      ptr2->data = 1;
      ptr->data = 2; 
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;     
    }
    else if(ptr->data==0 && ptr1!=nullptr && ptr2==nullptr){
      ptr1->data = 0;
      ptr->data = 1;
      ptr1 = ptr1->next;
    }
    else if(ptr->data==0 && ptr1==nullptr && ptr2!=nullptr){      
      ptr2->data = 0;
      ptr->data = 2;
      ptr2 = ptr2->next;
    }

    if(ptr->data==1 && ptr2!=nullptr && ptr1!=nullptr){
      ptr2->data = 1;
      ptr->data = 2;
      ptr2 = ptr2->next;
    }else if(ptr->data==1 && ptr2!= nullptr && ptr1==nullptr){
      ptr2->data = 1;
      ptr->data = 2;
      ptr1 = ptr2;
      ptr2 =ptr2->next;
    }
  }
}