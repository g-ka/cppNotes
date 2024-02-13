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
  Node(int dataue){
    data = dataue;
    left = nullptr;
    right = nullptr;
  }
  Node(int dataue, Node* ptr1, Node* ptr2){
    data = dataue;
    left = ptr1;
    right = ptr2;
  }
};

bool isSymmetric(Node* root);
bool isSymTree(Node* p, Node* q);

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

  bool result = isSymmetric(root);

  std::cout << result;

  return 0;
}

bool isSymmetric(Node* root){
  if(root == nullptr) return true;
  
  bool result = isSymTree(root->left, root->right);

  return result;
}

bool isSymTree(Node* p, Node* q){
  if (p == NULL && q == NULL) return true;
  else if (p == NULL || q == NULL) return false;

  return (p->data == q->data 
              && isSymTree(p->left, q->right) 
              && isSymTree(p->right, q->left)
          );
}