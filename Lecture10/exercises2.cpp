#include <iostream>
#include <string>
#include <vector>

// Names:
//Caleb Starkey
//Dylan Stump


// we'd like to write a function that is applicable to many types but
// we don't want to copy paste everything

// For example, here is a templated Add function
template <typename T>
T Add(T v1, T v2) {
    return v1 + v2;
}

template <typename T>
void AddToValues2(std::vector<T> &v1, T v2){
    for(int i = 0; i < int(v1.size()); i++){
        v1[i] = v1[i] + v2;
    }
}
// 6) implement a templated version of AddToValues, "AddToValues2".

struct node{
    int val;    
    struct node& operator+=(const node& node2){//to fix the += undefined for node error
        val+=node2.val;
        return *this;
    }
    struct node& operator+(const node& node2){//to fix the += undefined for node error
        val+=node2.val;
        return *this;
    }  
};


int main() {
    // 7) call AddToValues2, passing in an int vector and another int.
    std::vector<int> vec = {1,2,3,4};
    AddToValues2(vec,5);
    for(int i =0; i < vec.size(); i++){
        std::cout<< vec[i]<<std::endl;
    }

    // 8) compile this file to object code
    // g++ -Wall -std=c++17 exercises2.cpp -c
    // then run: nm -C exercises2.o | grep "AddToValues2"
    // How many versions of the AddToValues2 function are in the
    // compiled object code? Copy + paste the relevant lines here:
    //0000000000000000 W void AddToValues2<int>(std::vector<int, std::allocator<int> >&, int)

    // 9) call AddToValues2, passing in a vector of a non-int type and a value that you can add
    // successfully to the elements
    std::vector<double> vec2 = {1.1,2.2,3.3,4.4};
    AddToValues2(vec2,5.0);
    for(int i =0; i < vec2.size(); i++){
        std::cout<< vec2[i]<<std::endl;
    }
    // 10) compile this file to object code
    // g++ -Wall -std=c++17 exercises2.cpp -c
    // then run: nm -C exercises2.o | grep "AddToValues2"
    // How many versions of the AddToValues2 function are in the
    // compiled object code? Copy + paste the relevant lines here:
    //0000000000000000 W void AddToValues2<double>(std::vector<double, std::allocator<double> >&, double)
    //0000000000000000 W void AddToValues2<int>(std::vector<int, std::allocator<int> >&, int)

    // 11) Experiment to find calls to this function that you would like to work but that do
    // not yet work. for each function call that doesn't work, comment about what type of 
    // error is produced.
    // std::vector<std::string> vec3 = {"hi", "hello", "hey"};
    // AddToValues2(vec3,std::string("o"));
    // for(int i =0; i < vec3.size(); i++){
    //     std::cout<< vec3[i]<<std::endl;
    // }
    // std::vector<bool> vec4 = {true, false, true};
    // AddToValues2(vec4,true);
    // for(int i =0; i < vec4.size(); i++){
    //     std::cout<< vec4[i]<<std::endl;
    // }

    //function calls with different types don't work

    // 12) Create a struct that has an int field. Instantiate a vector of these structs.
    // Instantiate another instance of this struct.
    node n1;
    n1.val = 1;
    node n2;
    n2.val = 2;
    node n3;
    n3.val = 3;
    node n4;
    n4.val = 4;
    std::vector<node> nodeVect = {n1,n2,n3,n4};

    node iter;
    iter.val = 5;
    AddToValues2(nodeVect,iter);
    // 13) Call AddToValues2 w/ the vector of structs and single struct from #12
    // Is there an error? If yes, what is it?
    //
    // Answer: yes, it doesn't like any additive operators (+,+=) 

    // 14) If there was an error, attempt to fix it.

}
