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
  if (p == NULL && q == NULL) return true;
  else if (p == NULL || q == NULL) return false;

  return (p->data == q->data 
            && isSameTree(p->left, q->left) 
              && isSameTree(p->right, q->right)
        );
}