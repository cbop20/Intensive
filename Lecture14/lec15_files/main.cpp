#include <iostream>
#include <vector>

#include "Emotion.h"
#include "Creature.h"

// Names:
//Caleb Starkey
//Dylan Stump


int main() {
    // Part 1 (factory) 
    // ---------------
    // 4) get pointers to one of each type of your Emotion objects via your EmotionFactory. Then,
    // call the Emotion's get_count method to see how many Emotion objects have been instantiated.
    Emotion * e1 = EmotionFactory::GetHappy();
    Emotion * e2 = EmotionFactory::GetAngry();
    Emotion * e3 = EmotionFactory::GetHungry();

    std::cout << Emotion::get_count() << std::endl;
    // 5) are your EmotionFactory's Get____() methods static or non-static? Do you think that they should
    // be one or the other? Justify your answer. If your methods are static, what would change if they were
    // non-static? If they are non-static, what would change if they were static?
    
    //if static you dont need to create an object for them first, which easier on memory.

    // 6) Feel free to create more creatures here
    Creature original_creature(14);
    Creature second_creature(2);
    // 7) Infect your creatures with your emotions. Test out the Creature Spread method.
    original_creature.AddEmotion(e1);    
    original_creature.Spread(&second_creature);

    for (Emotion * d : original_creature.get_emotions() ) {
        std::cout << *(d) << std::endl;     
    }
    for (Emotion * d : second_creature.get_emotions() ) {
        std::cout << *(d) << std::endl;     
    }


    // STOP! Turn in Emotion.h, Emotion.cpp, and main.cpp on canvas

 
    // Part 2 (prototype) 
    // ---------------
    // 3) Create some new Creature * objects by using the Creature's Clone() method. Does this method use dynamic dispatch?
    // Answer: Yes
    // How did you test this?
    // The overwritten version of Clone is called for the subclass of Creature.
    Monster m(10);
    m.AddEmotion(e2);
    Creature *c = original_creature.Clone();
    Creature *d = m.Clone();

    std::cout << c->get_age() << std::endl;
    std::cout << d->get_age() << std:: endl;




    // If you finish:
    // -------------
    // 4) Write a new function in this file void ScienceLab(Creature * original) (not associated with any classes)
    // that takes an original creature and conducts experiments by cloning it and measuring the spread of emotion.
    // You have complete creative freedom here. Feel free to add methods to the Emotion/Creature classes.
    // (The only requirements are the function definition and that you must call Clone() within that function).
    //
    // Call your ScienceLab function as many times as is necessary for your experiments.
}

