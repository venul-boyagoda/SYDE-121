#ifndef a5_library_hpp
#define a5_library_hpp

#include <iostream>
#include <vector>
#include "a5_book.hpp"

using namespace std;

// PURPOSE: Models a library instance with corresponding collection of books
class Library {
    vector<Book> my_books;
    
public:
    // PURPOSE: Default/empty constructor for Library class
    Library();
    // Purpose: Parametric constructor with vector of books provided
    Library(vector<Book> new_books);
    
    // PURPOSE: Inserts a new book into library based on specified strings
    bool insert(string new_title, string new_authors, string new_dop);
    // PURPOSE: Inserts a new book object into library
    bool insert(Book new_book);
    
    // PURPOSE: Removes a book from the library based on specified strings
    bool remove(string new_title, string new_authors, string new_dop);
    // PURPOSE: Removes a book object from library
    bool remove(Book new_book);
    
    // PURPOSE: Service function that prints out all books in book collection
    void print();
};
#endif
