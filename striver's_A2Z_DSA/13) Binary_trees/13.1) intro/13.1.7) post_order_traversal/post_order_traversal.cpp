#include <iostream>

// TC: O(N)
// SC: O(H) => worst case: O(N)

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

void postOrder(Node* root);

int main(){

  Node* root = new Node(1);

  root->left = new Node(2);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->left->right->left = new Node(6);

  root->right = new Node(3);
  root->right->right = new Node(8);
  root->right->left = new Node(7);
  root->right->right->right = new Node(10);
  root->right->right->left = new Node(9); 

  postOrder(root);

  return 0;
}

void postOrder(Node* root){
  if(root == nullptr) return;
  postOrder(root->left);
  postOrder(root->right);
  std::cout << root->data << " ";
}