#include <iostream>
#include <vector>
#include "Library.h"
using namespace std;
// Name(s):
// Caleb Starkey
// Complete numbered coding tasks.
// Answer the questions with "Answer: " in the comments by writing your answer in the comments.
// some experiments might result in non-running/non-compiling code. Leave these experiments in, but
// comment them out.
// Turn in run_library.cpp, Library.h, and Library.cpp on Canvas before the end of class.
// make sure to leave a comment here and on canvas with your name and the name(s) of your partners.

int main() {
    // 1) Instantiate a couple Books. Set their fields equal to some values.
    // Print out the values of the books' fields.
    Book b1;
    b1.title = "Harry Potter and the Sorcerer's Stone";
    b1.author =  "J.K. Rowling";
    Book b2; 
    b2.title ="The Fellowship of the Ring";
    b2.author= "J.R.R Tolkien";
    cout << b1.author << ", " << b1.title << endl;
    cout << b2.author << ", " << b2.title << endl;
    // 2) Instantiate a Library.
    Library L1;
    // 3) Add a void Donate(Book b) method to your Library class.
    // Your Library should store the new book at the end of its shelf.


    // 4) Donate one of the Books that you instantiated to your Library.
    L1.donate(b1);

    // 5) Print out the books in the Library (use the given PrintBooks method)
    L1.PrintBooks();

    // 6) Change the title and/or author of the book that you donated to
    // something different.
    // Print out the new book information, then print out the books in your
    // Library. Did changing the Book information change it in your Library?
    //
    // Answer (and your hypothesis for why/why not): It did not change the information, when you donate the book it creates an exact copy of the stuct and adds it to the shelf of the library
    // they arent the same object
    b1.title = "The Hobbit";
    b1.author = "J.R.R Tolkien";
    L1.PrintBooks();
    // 7) Create two Books that are separate structs (not pointers or references)
    // but that have the same information.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer: The operator == for types Book and Book is not defined. 
    Book b3; 
    Book b4;
    b3.title = "Harry Potter and the Sorcerer's Stone";
    b3.author =  "J.K. Rowling";
    b4.title = "Harry Potter and the Sorcerer's Stone";
    b4.author =  "J.K. Rowling";
    // if (b3==b4){
    //     cout << "yes"<< endl;
    // }

    // 8) Create two Book references to your Books from # 7.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer: No these are not equal,error
    // Book &b3r = b3;
    // Book &b4r = b4;
    // if((b3r)==(b4r)){
    //     cout << "yes" << endl;
    // }
    // 9) Create two Book pointers to your Books from # 7.
    // use the == operator to test if they are equal. What happens?
    // if it succeeds, are these equal?
    //
    // Answer: No they are not, error
    // Book *b3p= &b3;
    // Book *b4p = &b4;
    // if(b3p==b4p){
    //     cout << "yes" << endl;
    // }

    // 10) Add a void Donate(Book b, int num_copies) method to your Library class.
    // your Library should add num_copies of Book b to its shelf. 
    L1.donate(b3,5);
    L1.PrintBooks();

    // 11) Finally, if you reach this far, work on finding a solution to making it so
    // that you would be able to do any of the comparisons from # 7, 8, and 9
}
