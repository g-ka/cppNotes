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

std::vector<std::vector<int>> zigzagLevelOrder(Node* root);

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

  std::vector<std::vector<int>> result =  zigzagLevelOrder(root);

  for(auto i: result){
    for(auto j: i){
      std::cout << j << " ";
    }
    std::cout << "\n";
  }

  return 0;
}

std::vector<std::vector<int>> zigzagLevelOrder(Node* root){
  std::vector<std::vector<int>> result;

  if(root == nullptr) return result;

  std::stack<Node*> st;
  std::queue<std::stack<Node*>> q;
  st.push(root);
  q.push(st);
  int isOdd = true;

  while(!q.empty()){
    std::stack<Node*> stTemp;
    std::vector<int> level;
    while(!q.front().empty()){
      Node* temp = q.front().top();
      q.front().pop();
      level.push_back(temp->data);
      if(isOdd){
        if(temp->left != nullptr) stTemp.push(temp->left);
        if(temp->right != nullptr) stTemp.push(temp->right);
      }else{
        if(temp->right != nullptr) stTemp.push(temp->right);
        if(temp->left != nullptr) stTemp.push(temp->left);
      }
    }
    result.push_back(level);
    if(!stTemp.empty()) q.push(stTemp);            
    q.pop();      
    isOdd = !isOdd;
  }

  return result;
}