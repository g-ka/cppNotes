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

std::vector<int> boundaryTraversal(Node* root);
void leftBoundary(Node* root ,std::vector<int>& v);
void leafNodes(Node* root, std::vector<int>& v);
void rightBoundary(Node* root, std::vector<int>& v);

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

  std::vector<int> boundary = boundaryTraversal(root);

  for(auto i: boundary) std::cout << i << " ";

  return 0;
}

std::vector<int> boundaryTraversal(Node* root){  
  std::vector<int> result;

  if(root == nullptr) return result;

  leftBoundary(root, result);
  leafNodes(root, result);
  rightBoundary(root, result);

  return result;
}

void leftBoundary(Node* root ,std::vector<int>& v){
  Node* temp = root;
  while(temp != nullptr){
    if(temp->left != nullptr){
      v.push_back(temp->data);
      temp = temp->left;      
    }else if(temp->right != nullptr){
      v.push_back(temp->data);
      temp = temp->right;
    }else temp = nullptr;
  }  
}

void leafNodes(Node* root, std::vector<int>& v){
  if(root->left == nullptr && root->right == nullptr) return;
  std::stack<Node*> st;
  st.push(root);
  while(!st.empty()){
    Node* temp = st.top();
    if(temp->left == nullptr && temp->right == nullptr) v.push_back(temp->data);
    st.pop();
    if(temp->right != nullptr) st.push(temp->right);
    if(temp->left != nullptr) st.push(temp->left);
  }
}

void rightBoundary(Node* root, std::vector<int>& v){
  if(root->right == nullptr) return;
  Node* temp = root->right;
  std::stack<int> st;
  while(temp != nullptr){
    if(temp->right != nullptr){
      st.push(temp->data);
      temp = temp->right;
    }else if(temp->left != nullptr){
      st.push(temp->data);
      temp = temp->left;
    }else temp = nullptr;
  }
  while(!st.empty()){
    v.push_back(st.top());
    st.pop();
  }
}