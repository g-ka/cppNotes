#include <iostream>
#include <bits/stdc++.h>

// TC: O(N)
// SC: O(N)

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

std::vector<std::vector<int>> levelOrder(Node* root);

int main(){

  Node* root = new Node(1);

  root->left = new Node(2);
  root->left->right = new Node(5);
  root->left->left = new Node(4);

  root->right = new Node(3);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  std::vector<std::vector<int>> result = levelOrder(root);

  for(auto i: result){
    for(auto j: i){
      std::cout << j << " ";
    }
    std::cout << "\n";
  }

  return 0;
}

std::vector<std::vector<int>> levelOrder(Node* root){
  std::queue<Node*> q;
  std::vector<std::vector<int>> result;
  if(root == nullptr) return result;
  q.push(root);
  while(!q.empty()){
    int qSize = q.size();
    std::vector<int> level;
    for(int i=0; i<qSize; i++){
      Node* qEl = q.front();
      level.push_back(qEl->data);
      q.pop();
      if(qEl->left != nullptr) q.push(qEl->left);
      if(qEl->right != nullptr) q.push(qEl->right);
    }   
    result.push_back(level); 
  }
  return result;
}