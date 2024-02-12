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
int heightOf(Node* root);

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
  if(root == nullptr) return true;

  std::stack<Node*> st;
  st.push(root);

  while(!st.empty()){
    Node* temp = st.top();
    int leftHeight = heightOf(root->left);
    int rightHeight = heightOf(root->right);
    if(abs(leftHeight - rightHeight) > 1) return false;
    st.pop();
    if(temp->right != nullptr) st.push(temp->right);
    if(temp->left != nullptr) st.push(temp->left);
  }

  return true;
}

int heightOf(Node* root){
  if(root == nullptr) return 0;

  int leftHeight = heightOf(root->left);
  int rightHeight = heightOf(root->right);

  return 1 + std::max(leftHeight, rightHeight);
}