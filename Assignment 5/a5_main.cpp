//***************************************************************************************************
// Name: Venul Boyagoda
// Student ID: 20909488
//
// Name: Janani Satkunarajah
// Student ID: 20885299
//
// SYDE 121: Assignment 5
// Filenames: a5_main.cpp, a5_book.hpp, a5_book.cpp, a5_library.hpp, a5_library.cpp
//
// We hereby declare that this code, submitted for credit for the course SYDE 121, is a product of our
// own efforts. This coded solution has not been plagarized from other sources and has not been
// knowingly plagarized by others.
//
// Project: Books and Library Classes
// Purpose: Implements a book class to store individual books and a Library class to store a vector of book instances with methods for printing
// attributes and inserting & removing books as well as functions for testing class methods.
// Due Date: Friday, November 20, 2020
//***************************************************************************************************

/*
Program Testing Scenarios:
- test all book and library constructor types
- test printing methods for book and library classes
- test insertion of new books and existing books in library (with parameters passed as string attributes and book instances)
- test removal of existing books and missing books in library (with parameters passed as string attributes or book instances)
 
Limitations: N/A
 - all the steps of the assignment were completed
 */

#include <iostream>
#include <cassert>
#include "a5_book.hpp"
#include "a5_library.hpp"
using namespace std;

void test_constructors() {
    // test scenarios
    Book my_book1("title1", "author1", "dop1");
    Book my_book2("title2", "author2");
    Book my_book3("title3");
    Book my_book4;
    my_book1.print();
    my_book2.print();
    my_book3.print();
    my_book4.print();
    
    vector<Book> my_books = {my_book1, my_book2, my_book3, my_book4};
    Library my_library1;
    Library my_library2(my_books);
    my_library1.print();
    my_library2.print();
}

void test_book_insertion() {
    // setup
    Book my_book1("title1", "author1", "dop1");
    Book my_book2("title2", "author2", "dop2");
    Book my_book3("title3", "author3");
    Book my_book4("title4", "author4", "dop4");
    Book my_book5("title1", "author1", "dop1"); //duplicate value
    vector<Book> my_books = {my_book1, my_book2, my_book3};
    Library my_library1(my_books);
    
    // test scenarios
    my_library1.insert(my_book4); //insert book that does not already exist with book object
    my_library1.insert(my_book5); //insert duplicate book that exists at beginning of vector with book object
    my_library1.insert("title5", "author5", "dop5"); //insert book that does not already exist with specified strings
    my_library1.insert("title3", "author3", "n/a"); //insert book that already exists in middle of vector with specifed strings
    my_library1.insert("title5", "author5", "dop5"); //insert book that already exists at end of vector with specifed strings
    my_library1.print();
}

void test_book_removal() {
    // setup book instances
    Book my_book1;
    Book my_book2 ("title2");
    Book my_book3("title3", "author3");
    Book my_book4("title4", "author4", "dop4");
    Book my_book5("title5", "author5", "dop5");
    Book my_book6("title6", "author6");
    
    // setup library instance
    vector <Book> test_books = {my_book1, my_book2, my_book3, my_book4, my_book5};
    Library my_library(test_books);
    my_library.print();
    
    // test scenarios (all assertions should pass)
    assert(my_library.remove(my_book1)); // test removal of book from beginning of library by passing book instance
    assert(my_library.remove("title5", "author5", "dop5")); // test removal of book from end of library using by passing string attributes
    assert(my_library.remove(my_book3)); // test removal of book from the middle of library
    assert(!my_library.remove(my_book1)); // test removal of a book that does not exist in the library by passing a book instance
    assert(!my_library.remove("title6", "author6", "n/a")); // test removal of a book that does not exist in the library by passing string attributes
    my_library.print(); // compare initial print of library with final print where my_book1, my_book3, and my_book 5 were removed
}

void execute_tests() {
    test_constructors();
    test_book_insertion();
    test_book_removal();
}

int main() {
    execute_tests();
}
