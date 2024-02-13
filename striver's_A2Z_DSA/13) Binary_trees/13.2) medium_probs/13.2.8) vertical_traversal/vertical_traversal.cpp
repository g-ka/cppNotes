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

std::vector<std::vector<int>> verticalView(Node* root);

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

  std::vector<std::vector<int>> result =  verticalView(root);

  for(auto i: result){
    for(auto j: i){
      std::cout << j << " ";
    }    
    std::cout << "\n";
  }

  return 0;
}

std::vector<std::vector<int>> verticalView(Node* root){
  std::vector<std::vector<int>> nonNegatives;
  std::vector<std::vector<int>> negatives;
  std::vector<std::vector<int>> result;
  std::queue<std::stack<std::pair<Node*, int>>> q;  
  std::stack<std::pair<Node*, int>> st;
  st.push({root, 0});
  q.push(st);

  while(!q.empty()){
    std::stack<std::pair<Node*, int>> stTemp;
    while(!q.front().empty()){
      std::pair<Node*, int> temp = q.front().top();
      Node* node = temp.first;
      int pos = temp.second;
      if(pos < 0){
        if(negatives.size() == abs(pos) - 1){
          std::vector<int> tempV{node->data};
          negatives.push_back(tempV);
        }else negatives[abs(pos) - 1].push_back(node->data);
      }else{
        if(nonNegatives.size() == pos){
          std::vector<int> tempV{node->data};
          nonNegatives.push_back(tempV);
        }else nonNegatives[pos].push_back(node->data);
      }
      q.front().pop();
      if(node->right != nullptr) stTemp.push({node->right, pos+1});
      if(node->left != nullptr) stTemp.push({node->left, pos-1});
    }
    if(!stTemp.empty()) q.push(stTemp);
    q.pop();
  }

  for(int i=negatives.size()-1; i>=0; i--){
    result.push_back(negatives[i]);
  }
  for(int i=0; i<nonNegatives.size(); i++){
    result.push_back(nonNegatives[i]);
  }

  return result;
}