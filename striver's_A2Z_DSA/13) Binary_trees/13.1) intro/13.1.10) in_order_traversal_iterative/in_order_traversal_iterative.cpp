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

std::vector<int> inOrder(Node* root);

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

  std::vector<int> result =  inOrder(root);

  for(auto i: result) std::cout << i << " ";

  return 0;
}

std::vector<int> inOrder(Node* root){
  std::vector<int> result;
  std::stack<Node*> st;
  st.push(root);

  if(root == nullptr) return result;

  while(!st.empty()){
    if(st.top()->left != nullptr) st.push(st.top()->left);
    else{
      while(st.top()->right == nullptr){
        result.push_back(st.top()->data);
        st.pop();
        if(st.empty()) return result;
      }
      result.push_back(st.top()->data);
      Node* toPop = st.top();
      st.pop();
      st.push(toPop->right);
    }
  }
}