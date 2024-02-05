#include <iostream>
#include <bits/stdc++.h>

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
std::vector<std::pair<int, int>> findPairs(Node* head, int k);

int main(){

  Node* head = nullptr;
  Node* tail = nullptr;
  insertLast(1, head, tail);
  insertLast(2, head, tail);
  insertLast(3, head, tail);
  insertLast(4, head, tail);
  insertLast(9, head, tail);  

  for(Node* ptr=head; ptr!=nullptr; ptr=ptr->next) std::cout << ptr->data << " ";

  std::vector<std::pair<int, int>> pairs =  findPairs(head, 5);

  std::cout << "\npairs:\n";
  for(auto i: pairs) std::cout << i.first << " " << i.second << "\n";

  return 0;
}

void insertLast(int value, Node*& head, Node*& tail){
  Node* currentNode = new Node(value);
  if(head == nullptr){
    head = currentNode;
    tail = currentNode;
  }else{
    tail->next = currentNode;
    currentNode->back = tail;
    tail = currentNode;
  }
}

std::vector<std::pair<int, int>> findPairs(Node* head, int k){
  std::vector<std::pair<int, int>> result;
  Node* ptr = head;
  while(ptr->next!=nullptr) ptr = ptr->next;
  Node* tail = ptr;
  while(head!=tail){
    if(head->data + tail->data == k){
        std::pair<int, int> sumPair = {head->data, tail->data};
        result.push_back(sumPair);
        if(head->next->data == head->data) head = head->next;
        else if(tail->back->data == tail->data) tail = tail->back;
        else head = head->next;
    }else if(head->data + tail->data < k) head = head->next;
    else tail = tail->back;                    
  }
  return result;
}
