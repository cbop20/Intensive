#include <iostream>
#include <string>
#include <vector>

// Names:
//Caleb Starkey
//Dylan Stump


// 1) implement two functions, AddToValues(std::vector<int> v1, int v2)
// and AddToValues(std::vector<double> v1, double v2)
void AddToValues(std::vector<int> &v1,int v2){
    for(int i =0; i < int(v1.size()); i++){
        v1[i]+=v2;
    }
}
void AddToValues(std::vector<double> &v1,double v2){
    for(double i =0; i < int(v1.size()); i++){
        v1[i]+=v2;
    }
}
// 2) Do your AddToValues functions have return values? why/ why not?
// Answer: No I passed by reference


int main() {
    // 3) Instantiate an int vector
    // 4) call AddToValues, passing in your int vector and another int.
    std::vector<int> vec = {1,2,3,4};
    AddToValues(vec,5);
    for(int i =0; i < vec.size(); i++){
        std::cout<< vec[i]<<std::endl;
    }
    


    // 5) compile this file to object code
    // g++ -std=c++17 -Wall exercises.cpp -c

    // then run the command: nm -C exercises.o | grep "AddToValues"
    // How many versions of the AddToValues function are in the
    // compiled object code? Copy + paste the relevant lines here:
    //00000000000002e7 t _GLOBAL__sub_I__Z11AddToValuesRSt6vectorIiSaIiEEi
    //0000000000000063 T AddToValues(std::vector<double, std::allocator<double> >&, double)
    //0000000000000000 T AddToValues(std::vector<int, std::allocator<int> >&, int)
    
    // If the -C flag isn't working, you can omit it and still complete the exercise--this flag
    // makes the output easier to read but isn't strictly necessary
}
