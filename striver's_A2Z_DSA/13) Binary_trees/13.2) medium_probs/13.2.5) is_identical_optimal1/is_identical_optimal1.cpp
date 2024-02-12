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

bool isSameTree(Node* p, Node* q);

int main(){

  Node* root1 = new Node(1);

  root1->left = new Node(2);
  root1->left->left = new Node(4);
  root1->left->right = new Node(5);
  root1->left->right->left = new Node(6);

  root1->right = new Node(3);
  root1->right->right = new Node(8);
  root1->right->left = new Node(7);
  root1->right->right->right = new Node(10);
  root1->right->right->left = new Node(9);

  Node* root2 = new Node(1);

  root2->left = new Node(2);
  root2->left->left = new Node(4);
  root2->left->right = new Node(5);
  root2->left->right->left = new Node(6);

  root2->right = new Node(3);
  root2->right->right = new Node(8);
  root2->right->left = new Node(7);
  root2->right->right->right = new Node(10);
  root2->right->right->left = new Node(9);

  bool result = isSameTree(root1, root2);

  std::cout << result;

  return 0;
}

bool isSameTree(Node* p, Node* q){

  if(p == nullptr && q == nullptr) return true;

  std::stack<Node*> st1;
  std::stack<Node*> st2;
  st1.push(p);
  st2.push(q);

  while(!st1.empty() || !st2.empty()){
      Node* temp1 = st1.top();
      Node* temp2 = st2.top();

      if(temp2 == nullptr || temp1 == nullptr) return false;
      if(temp1->data != temp2->data) return false;

      st1.pop();
      st2.pop();

      if(temp1->left != nullptr || temp2->left != nullptr){
          st1.push(temp1->left);
          st2.push(temp2->left);
      }
      if(temp1->right != nullptr || temp2->right != nullptr){
          st1.push(temp1->right);
          st2.push(temp2->right);
      }
  }

  return true;
}