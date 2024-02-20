#include <iostream>

class Entity{
  public: 
  virtual std::string getName(){
    return "Entity";
  }
};

class Child : public Entity{
  private: 
  std::string myName;

  public:
  Child(std::string name){
    myName = name;
  }
  std::string getName() override{
    return myName;
  }
};

int main(){

  Entity* e = new Entity();
  std::cout << e->getName() << std::endl;

  Child* c = new Child("kapilan");
  std::cout << c->getName() << std::endl;

  e = c;
  std::cout << e->getName();

  return 0;
}