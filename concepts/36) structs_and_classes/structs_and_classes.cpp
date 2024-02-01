#include <iostream>

// Three types of access modifiers:
// 1) public: can be accessed in any class of the code
// 2) private: can be accessed only inside the class where it is defined
// 3) protected: same as private except that it can be used inside its subclass

// Two ways to create member functions:
// 1) inside class
// 2) outside class

// -- constructors and destructors are two special type of member functions
// -- The constructor will be called everytime a new instance of the class is created
// -- The destructor is called everytime an object reaches its end of the scope, thus
// deleted

// -- key difference between structures and classes:
// 1) default access modifier of structs are public while for classes it is private
// 2) structs doesn't support inheritance, polymorphism and abstraciton while classes does it
// 3) NULL values are not possible in structs but possible in classes 
// 4) structs are stored in stack memory while classes are stored in heap memory
// 5) keyword 'struct' is used to create structs while 'class' is used for classes
// -- similarities between structures and classes:
// 1) both support encapsulation
// 2) both have data members and member functions
// 3) both have constructors and destructors

// It is a convention to declare classes with first letter caps
class car{
  // access modifier:
  public:

  // data memebers:
  std::string name;
  std::string model;
  bool isReg = NULL;

  // member functions:
  void setName(std::string carName){
    name = carName;
  }
  void setModel(std::string carModel){
    model = carModel;
  }
  void setReg(bool carIsReg);
  void displayDetails(){
    std::cout << name << " " << model << " " << isReg << "\n";
  }

  // constructors:
  car(){
    return;
  }
  car(std::string carName){
    name = carName;
  }
  car(std::string carName, std::string carModel){
    name = carName;
    model = carModel;
  }

  // destructors:
  ~car(){
    std::cout << "Destructor\n";
  }
};

// defining a member function outside the class
void car::setReg(bool carIsReg){
  isReg = carIsReg;
}

int main(){

  // creating an object without passing arguments to constructors:
  car chevy;
  chevy.setName("Chevrolet");
  chevy.setModel("Camaro");
  chevy.setReg(true);
  
  chevy.displayDetails();

  // creating an object by passing arguments to constructors:
  car dodger("Dodger", "Challenger");
  dodger.setReg(false);
  std::cout << "Dodger isReg: " << dodger.isReg << "\n";

  dodger.displayDetails();

  // creating a pointer object:
  car *startNode = new car("Ford", "Mustang");
  std::cout << "Memory location: " << startNode << "\n";
  std::cout << startNode->name << " " << startNode->model << "\n";

  return 0;
}