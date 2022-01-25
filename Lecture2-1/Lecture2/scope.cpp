#include <iostream>

// scope: "what can we see right here"
// - what variables/functions/other can we access from inside x, where x is a function, method, etc.

// 1) what happens in c++ if you try to acces a variable out of scope?
    //The variable is unaccesible, normally leading to a variable undefined error
// 2) what happens if we make everything global?
    //Sometimes it's good to keep things within a smaller scope so you don't accidently change them later. ie i is a popular name for a for loop iterator and if we declared it globably
    //and used it again later it could be a problem. Also with enough variables you start to take up a lot of memory. 

// Summary:
// pass-by-value vs. pass-by-reference
// pass-by-value: give the function a copy of the value
// pass-by-reference: give the address of the location of the value


// *************************************************


// When you are done: turn in your file on canvas

// Names (be sure to include the initial of your last name(s)!):
//Caleb S
//Noah N
//Jonas C
//Richard R

// 1) Write a function that demonstrates whether ints are pass-by-value or pass-by-reference
// (do not use pointers or c++ references in this function)
// Answer:
void testInt(int x){
    x++;
}

// 2) Write a function that tests demonstrates whether strings (std::string) are pass-by-value or pass-by-reference
// (do not use pointers or c++ references in this function)
// Answer:
void testString(std::string str){
    str = "modified";
}

// 3) Write a function that demonstrates whether arrays are pass-by-value or pass-by-reference
// recall: to initialize an array-- type name[] = {comma separated elements};
// (do not use pointers or c++ references in this function)
// Answer:
void testArray(int foo[5]){
    foo[2]=2;
}

// 4) Write a function that demonstrates whether vectors are pass-by-value or pass-by-reference
// Answer:


int main() {
    int x =5;
    std::cout <<"x before call: " << x << std::endl;
    testInt(x);
    std::cout <<"x after call: " << x << std::endl;
    // code to call your functions goes here.
    
    std::string str = "Hello World";
    std::cout <<"str before call: " << str << std::endl;
    testString(str);
    std::cout <<"str after call: " << str << std::endl;

    int fun[5]={1,1,1,1,1};
    std::cout <<"Array before call: ";
    for(int i=0;i<5;i++){
        std::cout<<fun[i];
    }
    std::cout<< std:: endl;
    testArray(fun);
    std::cout <<"Array before call: ";
    for(int i=0;i<5;i++){
        std::cout<<fun[i];
    }
    std::cout<< std:: endl;
    // you may find it useful to print out values in main as well as inside your functions
    // to appropriately demonstrate whether the given type is pass-by-value or 
    // pass-by-reference

}
