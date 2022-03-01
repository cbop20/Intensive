#include <iostream>
#include <vector>
#include "Animal.h"
// Name(s): Caleb Starkey Dylan Stump

int main() {

  Reptile ralph("alligator");
  std::cout << ralph.MakeSound() << std::endl;

  // 1) Instantiate another animal 
  Mammal tony;
  // 2) Call the Race method of animal
  ralph.Race(tony);
  // 3) Go to the Animal.h file and define some new subclasses of animal
  // Define one class that inherits from Animal and
  // one class that inherits from a child class of Animal
  // 4) Instantiate at least one object of each class you defined for #3
  Turtle crush;
  Bird tweety;
  
  Animal *t = &tony;
  Animal *b = &tweety;
  Animal *c = &crush;
  Animal *r = &ralph;
  // 5) Have a tournament between the animals that you have instantiated 
  std::vector<Animal*> animals = {t,b,c,r};
  for(int i = 0; i < animals.size(); i ++){
    for(int j = 0; j < animals.size(); j++){
      if(i!=j){
        animals[i]->Race(*animals[j]);
      }
    }
  }


  for(int i = 0; i <animals.size();i++){
    animals[i]->GetSpeed();
    animals[i]->MakeSound();
  }

  // 6) turn in Animal.h and main.cpp on canvas
	return 0;
}
