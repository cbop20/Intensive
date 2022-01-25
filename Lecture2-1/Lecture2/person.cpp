#include <iostream>
// primarily about structure for data
struct Person {
    std::string name;
    int age;
};

// data + functionality
class Family {
    public:
        Family(int num) {
            num_ = num;
        }

        void Grow(int num_persons) {num_ += num_persons;}; // method

    private:
        // fields/attributes
        int num_;
};

int main() {
    Person p;
    p.name = "Alice";
    p.age = 12;


    Family f1(4);
    f1.Grow(4);


    Family * f2 = new Family(10);
    f2->Grow(8);
    Family * f3 = f2;
    
    // if(*f2==*f3){
    //     std::cout << "works";
    // }
    //std::cout << p;

    // Exercises: find out if two different structs containing the same data are ==
        //thros an error as the operator == isn't defined for types Family
    // What happens if you try to << a struct to cout? why?
        //Lots of errors as it tries to convert the struct into a type that it can cout, first error is that << is not defined for type p

}
