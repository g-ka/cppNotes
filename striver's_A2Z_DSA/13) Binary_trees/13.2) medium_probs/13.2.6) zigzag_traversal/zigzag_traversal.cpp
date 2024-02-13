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

std::vector<std::list<int>> zigzagLevelOrder(Node* root);

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

  std::vector<std::list<int>> result =  zigzagLevelOrder(root);

  for(auto i: result){
    for(auto j: i){
      std::cout << j << " ";
    }
    std::cout << "\n";
  }

  return 0;
}

std::vector<std::list<int>> zigzagLevelOrder(Node* root){
  std::queue<Node*> q;
  std::vector<std::list<int>> result;
  q.push(root);
  int count = 1;
  bool isOdd = true;

  while(!q.empty()){
    std::list<int> level;
    int countTemp = count;
    count = 0;

    for(int i=countTemp; i>0; i--){
      Node* temp = q.front();
      q.pop();
      
      if(isOdd) level.push_back(temp->data);
      else level.push_front(temp->data);

      if(temp->left != nullptr){
        q.push(temp->left);
        count++;
      }
      if(temp->right != nullptr){
        q.push(temp->right);
        count++;
      }
    }

    isOdd = !isOdd;
    result.push_back(level);
  }

  return result;
}