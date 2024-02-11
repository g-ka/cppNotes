#include <iostream>

// TC: O(N) => N: number of nodes in binary tree
// SC: O(H) => H: height of the binary tree
// SC is calculated based on stack memory due to recursion function calls
// SC worst case is in skew/degenerate tree where H = N => O(N) 

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

void preOrder(Node* root);

int main(){

  Node* root = new Node(1);

  root->left = new Node(2);
  root->right = new Node(3);

  root->left->left = new Node(4);
  root->left->right = new Node(5);

  root->left->right->left = new Node(6);

  root->right->left = new Node(7);
  root->right->right = new Node(8);

  root->right->right->left = new Node(9);
  root->right->right->right = new Node(10);

  preOrder(root);

  return 0;
}

void preOrder(Node* root){
  if(root == nullptr) return;
  std::cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right); 
}