#include <iostream>

// -- datatype of a pointer must be same as the datatype of the variable it points to.
// -- so if it points an object then its datatype must be same as that of the object.

// -- Key differences between arrays and linked list:
// 1) arrays are of fixed size, while linked list is not.
// 2) each element in linked list is of user-defined datatype using class containing data and pointer.
// 3) depending on 32 or 64 bit system the size of linked list may vary(as it has addredd stored in pointer), while
// array's size is always fixed.

// -- Applications of Linked Lists:
// 1) creates two data structures -> stacks and queues.
// 2) dynamic memory allocation.
// 3) web browsers.

class Node{
  public:
  int data;
  Node* next;
  Node(int data1, Node* next1){
    data = data1;
    next = next1;
  }
  Node(int data1){
    data = data1;
    next = nullptr;
  }
};

int main(){

  Node x1(1, nullptr);
  Node* y1 = &x1;

  Node x2(2, nullptr);
  x1.next = &x2;

  std::cout << "x1 data: " << x1.data << " " << y1->data << "\n";
  std::cout << "x2 data: " << x2.data << " " << x1.next->data << " " << "\n";

  return 0;
}