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

Node* nodePath(Node* root, Node* p, std::stack<int>& path);

int main(){

  Node* root = new Node(3);

  root->left = new Node(5);
  root->left->left = new Node(6);
  root->left->right = new Node(2);
  root->left->right->left = new Node(7);
  root->left->right->right = new Node(4);

  root->right = new Node(1);
  root->right->left = new Node(0);
  root->right->right = new Node(8);

  std::stack<int> path;
  
  nodePath(root, root->right->left, path);

  while(!path.empty()){
    std::cout << path.top() << " ";
    path.pop();
  }

  return 0;
}

Node* nodePath(Node* root, Node* p, std::stack<int>& path){  
  if(root == nullptr) return root;
  if(root == p){
    path.push(root->data);
    return root;
  }

  Node* left = nodePath(root->left, p, path);
  Node* right = nodePath(root->right, p, path);

  if(left || right){
    path.push(root->data);
    return root;
  }
  else return nullptr;  
}