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

std::vector<int> rightView(Node* root);

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

  std::vector<int> result =  rightView(root);

  for(auto i: result){
      std::cout << i << " ";
  }

  return 0;
}

std::vector<int> rightView(Node* root){
  std::vector<int> result;

  if(root == nullptr) return result;

  std::queue<std::queue<Node*>> q;
  std::queue<Node*> qin;
  qin.push(root);
  q.push(qin);

  while(!q.empty()){
    std::queue<Node*> qinTemp;

    while(!q.front().empty()){
      Node* temp = q.front().front();
      q.front().pop();

      if(q.front().empty()) result.push_back(temp->data);

      if(temp->left != nullptr) qinTemp.push(temp->left);
      if(temp->right != nullptr) qinTemp.push(temp->right);
    }

    q.pop();
    if(!qinTemp.empty()) q.push(qinTemp);   
  }     

  return result;
}