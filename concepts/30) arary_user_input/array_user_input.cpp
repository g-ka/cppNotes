#include <iostream>

// This is just a demonstration of getting input from users into an array and displaying them
// Here we get fav cars(max 5) of users as input and display it

int main() {

  std::string cars[5];
  std::string temp;

  for(int i=0; i<5; i++){

    std::cout << "Enter car #" << i+1 << " or press 'q' to exit: ";    
    std::getline(std::cin, temp);

    if(temp == "q"){
      break;
    }else{
      cars[i] = temp;
    }

  }  

  std::cout << "Your favourite cars:\n";
  for(int i=0; !cars[i].empty(); i++){
    std::cout << cars[i] << "\n";
  } 

  return 0;
}