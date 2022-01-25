#include <iostream>
using namespace std;
// Name:
//Caleb Starkey

// Write any functions you need here!
void increment(int *i){
        (*i)++;
    }
void decrement(int &i){
    i++;
}
void plus2(const int &i, int *o){
    *o = i + 2;
}

class Node{
    public:
        int val;
        Node(){
            val = 0;
        };
        Node(int i){
            val = i;
        };
        Node operator+(const Node& n2){
            Node n1(this->val + n2.val);
            return n1;
        }
        bool operator==(const Node& n2){
            if(this->val == n2.val){
                return true;
            }
            else{
                return false;
            }
        }
};


int main() {
    // Add as many prints to cout as you need to answer the questions.
    // Leave them in your code when you turn it in.
    // If you have lines of code that cause errors that test the questions,
    // leave this code in your file but comment it out.
    
    // 1) Declare an int
    int x = 0;
    // 2) Declare a pointer to that int
    int *p = &x;
    // 3) Increment the int via the pointer
    (*p)++;
    // 4) Declare a reference to your int
    int &ref = x;
    // 5) Increment the int via the reference
    ref++;
    // 6) When you increment the int via the variable declared in #1, which
    // variables will be modified to see the changes? (the pointer , reference or both?)
    // Answer: Both of them will
    cout << *p << "," << x << "," << ref <<endl;
    // 7) When you increment the int via the pointer declared in #2, which
    // variables will be modified to see the changes?
    // Answer: x, pointer, and the ref

    // 8) When you increment the int via the reference declared in #4, which
    // variables will be modified to see the changes?
    // Answer: x,pointer, and the ref

    // 9) Write a function that takes an int * parameter. How would you pass the 
    // variable from #1 into this function? (write the function header and function call below)
    // void increment(int *i){
    //     (*i)++;
    // }
    increment(p);
    cout<<*p<<endl;
    // 10) Can you pass your reference from #4 to the function from #9 without accessing its address?
    // Answer: no
    //increment(ref);

    // 11) Write a function that takes an int & parameter. How would you pass the 
    // variable from #1 into this function? (write the function header and call below)
    // void decrement(int &i){
    //     i++;
    // }
    decrement(ref);

    // 12) Can you pass your pointer from #2 to the function from #11 without dereferencing it?
    // Answer: No
    //decrement(p);
    // 13) Can you pass your reference from #4 to the function from #11?
    // Answer:Yes

    // 14) Write a function that takes one const reference input parameter and one pointer
    // output parameter. The function should fill in the value of the output parameter based
    // on the value of the input parameter. (what it does exactly is up to you).
    // Call your function 3 times below. Be sure to include output as necessary to be sure
    // your function works as described.
    // void plus2(const int &i, int *o){
    //     *o = i + 2;
    // }
    int y = 0;
    int z = 0;
    int &pref = y;
    int *pon = &z;

    plus2(pref,pon);
    cout << pref << *pon << endl;
    y=5;
    plus2(pref,pon);
    cout << pref << ","<< *pon << endl;
    y=10;
    plus2(pref,pon);
    cout << pref << "," << *pon << endl;
    // 15) What is/are the difference(s) between output parameters and return values?
    // Answer: return values are copies of variables that you have to set a variable = to to save. output parameters are changed by the function itself and thus nothing additional needs to be passed to keep them

    // 16) Create a custom class with at least one private field/class attribute. Overload the == and + operator for this class
    // such that == can be used to compare the objects of the class and + can be used to add
    // 2 objects of the class together. Implement an appropriate constructor for your class.
    // When you overload these operators, the resulting return value should make sense.
    // Instantiate at least 2 objects of this class and perform the == and + operations on them.
    // hint: for operator+, the function signature when implemented as a member function of the Object class is:
    // Object operator+(const Object &other)
    // Answer:

    Node node1(3);
    Node node2(5);
    cout << (node1 + node2).val << endl;
    cout << (node1 == node2) << endl;
}
