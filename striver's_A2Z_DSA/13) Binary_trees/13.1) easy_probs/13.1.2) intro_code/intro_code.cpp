#include <iostream>

class Node{
  public:
  int data;
  Node* left;
  Node* right;
  Node(){
    data = 0;
    left = nullptr;
    right = nullptr;
  }
  Node(int value){
    data = value;
    left = nullptr;
    right = nullptr;
  }
  Node(int value, Node* ptr1, Node* ptr2){
    data = value;
    left = ptr1;
    right = ptr2;
  }
};

int main(){

  Node* root = new Node(1);

  root->left = new Node(2);
  root->right = new Node(3);

  root->left->right = new Node(4);

  std::cout << root->data << "\n"; // 1
  std::cout << root->left->data << "\n"; // 2
  std::cout << root->right->data << "\n"; // 3
  std::cout << root->left->right->data << "\n"; // 3

  return 0;
}