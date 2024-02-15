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

Node* LCA(Node* root, Node* p, Node* q);

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

  Node* link = LCA(root, root->left->left, root->left->right->right);

  std::cout << link->data;

  return 0;
}

Node* LCA(Node* root, Node* p, Node* q){
  if(root == nullptr || root == p || root == q) return root;

  Node* left = LCA(root->left, p, q);
  Node* right = LCA(root->right, p, q);

  if(left == nullptr) return right;
  else if(right == nullptr) return left;
  else return root;    
}