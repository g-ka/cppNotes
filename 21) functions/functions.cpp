#include <iostream>

// function is simply a block of reusable code

/*
We can declare functions in 2 ways:
1) before main function (Ex: goodMorning)
2) after main function (Ex: goodAfternoon)
*/
 
void goodMorning(std::string name, int time) {
  std::cout << "Good Morning " << name << "!\nLets meet at " << time << " PM.\n";
}

void goodAfternoon(std::string, int); //If we define our function after main function then we should declare
// it before main function with its name and datatypes of the paramenters it recieves as shown above.

int main() {

  std::string firstName = "Kaphil";
  int meetingTime = 2;
  int workDate = 10;

  goodMorning(firstName, meetingTime); // passing arguments
  goodAfternoon(firstName, workDate); // passing arguments

  return 0;
}

void goodAfternoon(std::string name, int date) {
  std::cout << "Its a great meet " << name << "!\nLets begin our work from January " << date << "th.";
}