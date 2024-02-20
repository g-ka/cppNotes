#include <iostream>

class Complex{
  private: 
  int real;
  int imaginary;

  public:
  Complex(){
    real = 0;
    imaginary = 0;
  }
  Complex(int r, int imag){
    real = r;
    imaginary = imag;
  }
  Complex operator+(Complex num){
    Complex newNum;
    newNum.real = real + num.real;
    newNum.imaginary = imaginary + num.imaginary;
    return newNum;
  }
  void print(){
    std::cout << real << " + i" << imaginary << std::endl;
  }
};

int main(){

  Complex cNum1(10, 2);
  cNum1.print();

  Complex cNum2(3, 5);
  cNum2.print();  

  Complex iNum = cNum1 + cNum2;
  iNum.print();

  return 0;
}