#include <iostream>
#include <bits/stdc++.h>

bool isBalanced(std::string s);

int main(){

  std::string s = "()[]{}";

  bool result = isBalanced(s);

  std::cout << result;

  return 0;
}

bool isBalanced(std::string s){
  std::stack<int> st;

  for(auto i: s){
    if(i=='{' || i=='[' || i=='(') st.push(i);
    else{
      if(st.empty()) return false;

      if(i=='}'){
        if(st.top()!='{') return false;
        else st.pop();
      }else if(i==']'){
        if(st.top()!='[') return false;
        else st.pop();
      }else{
        if(st.top()!='(') return false;
        else st.pop();
      }
    }
  }

  return st.empty();
}