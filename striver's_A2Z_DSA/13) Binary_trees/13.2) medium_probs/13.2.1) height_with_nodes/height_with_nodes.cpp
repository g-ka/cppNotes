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

std::pair<std::stack<Node*>, int> heightOf(Node* root);

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

  std::pair<std::stack<Node*>, int> result = heightOf(root);

  std::cout << "Height: " << result.second << "\n";

  while(!result.first.empty()){
    std::cout << result.first.top()->data << " ";
    result.first.pop();
  }

  return 0;
}

std::pair<std::stack<Node*>, int> heightOf(Node* root){  
  std::stack<Node*> chain;
  std::stack<Node*> st;
  st.push(root);
  int maxDepth = 0;
  int depth = 0;

  if(root == nullptr) return {chain, 0};

  while(!st.empty()){
    Node* temp = st.top();
    if(chain.empty()){
      chain.push(temp);
      maxDepth++;
      depth++;
    }
    else{
      while(chain.top()->right != temp && chain.top()->left != temp){
        chain.pop();
        depth--;
      }
      chain.push(temp);
      depth++;
      if(depth > maxDepth) maxDepth = depth;
    }
    st.pop();
    if(temp->right != nullptr) st.push(temp->right);
    if(temp->left != nullptr) st.push(temp->left);
  }

  return {chain, maxDepth};
}