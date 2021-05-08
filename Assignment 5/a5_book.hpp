#ifndef a5_book_hpp
#define a5_book_hpp

#include <iostream>
using namespace std;

// PURPOSE: Models book instance with the corresponsing attributes
class Book {
    string book_title, book_authors, date_of_publication;
    
public:
    // PURPOSE: Default/empty contructor for book class
    Book();
    // PURPOSE: Parametric constructor with only title specified
    Book(string new_title);
    // PURPOSE: Parametric constructor with title and authors specified
    Book(string new_title, string new_authors);
    // PURPOSE: Parametric constructor with all 3 atributes specified
    Book(string new_title, string new_authors, string new_dop);
    
    // PURPOSE: Service function that prints out all the attribute values
    void print();
    
    // PURPOSE: Accessor methods to access member atributes
    string get_title();
    string get_authors();
    string get_dop();
};
#endif
