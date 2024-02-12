#include <iostream>
#include <bits/stdc++.h>

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

bool isBalanced(Node* root);
int heightOf(Node* root, int& levDiff);

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

  bool result = isBalanced(root);

  std::cout << result;

  return 0;
}

bool isBalanced(Node* root){
  int levDiff = 0;

  heightOf(root, levDiff);

  if(levDiff > 1) return false;
  else return true;
}

int heightOf(Node* root, int& levDiff){
  if(root == nullptr) return 0;

  int leftHeight = heightOf(root->left, levDiff);
  int rightHeight = heightOf(root->right, levDiff);

  levDiff = std::max(levDiff, abs(leftHeight - rightHeight));

  return 1 + std::max(leftHeight, rightHeight);
}