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

int maxPathSum(Node* root);
int sumOf(Node* root, int& maxSum);

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

  int maxSum = maxPathSum(root);

  std::cout << maxSum;

  return 0;
}

int maxPathSum(Node* root){
  int maxSum = root->data;

  sumOf(root, maxSum);

  return maxSum;
}

int sumOf(Node* root, int& maxSum){
  if(root == nullptr) return 0;

  int leftSum = sumOf(root->left, maxSum);
  int rightSum = sumOf(root->right, maxSum);
  
  maxSum = std::max(maxSum, leftSum + root->data + rightSum);

  if(leftSum < 0 && rightSum < 0){
    if(root->data < 0) return 0;
    else return root->data;
  }
  else{
    if(root->data + std::max(leftSum, rightSum) < 0) return 0;
    else return root->data + std::max(leftSum, rightSum);
  }
}