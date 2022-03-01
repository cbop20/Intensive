#include <iostream>
#include "Earth.h"

// Names:
//

int main(int argc, char **argv){
    // 0) Implement your Earth's constructor in Earth.cpp

    // 1) Get an instance of your earth object
    Earth &earth = Earth::GetInstance();
    // 2) Get another instance of your earth object
    Earth &earth2 = Earth::GetInstance();
    // 3) Test to see if the two Earth instances from #1 and #2 are stored at the same
    // location in memory.
    std::cout << (&earth == &earth2) << std::endl;
    //they are

    // 3) Call IncreasePopulation from one of your Earth instances. Can you see this change
    // from your other Earth instance?
    earth.IncreasePopulation();
    std::cout << earth2.get_population() << std::endl;

    //yes you can

    // 4) Create a public field in your Earth object. Do you need an instance of an Earth object
    // to access this field?
    std::cout << Earth::continents std::endl;
	return 0;
}
