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

int diameterOf(Node* root);
int heightOf(Node* root, int& diameter);

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

  int diameter = diameterOf(root);

  std::cout << diameter;

  return 0;
}

int diameterOf(Node* root){
  int diameter = 0;

  heightOf(root, diameter);

  return diameter;
}

int heightOf(Node* root, int& diameter){
  if(root == nullptr) return 0;

  int leftHeight = heightOf(root->left, diameter);
  int rightHeight = heightOf(root->right, diameter);

  diameter = std::max(diameter, leftHeight + rightHeight);

  return 1 + std::max(leftHeight, rightHeight);
}