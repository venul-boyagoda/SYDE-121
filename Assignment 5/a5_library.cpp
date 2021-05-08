#include "a5_library.hpp"

Library::Library() {} // vector<Book> will be automatically initialized

Library::Library(vector<Book> new_books) :
// copy new books vector into my books vector
my_books(new_books) {}

bool Library::insert(Book new_book) {
    // step1. declare and initialize bool variable
    bool book_exists = false;
    
    // step2. iterate through vector elements and check if new book already exists
    for (int index = 0; index < my_books.size() && !book_exists; index++) {
            book_exists = my_books[index].get_title() == new_book.get_title();
            book_exists = book_exists && my_books[index].get_authors() == new_book.get_authors();
            book_exists = book_exists && my_books[index].get_dop() == new_book.get_dop();
    }
    
    // step3. add new book if it does not exist
    if (!book_exists) {
        my_books.push_back(new_book);
    }
    
    return !book_exists;
}

bool Library::insert(string new_title, string new_authors, string new_dop) {
    // create Book object with specified strings
    Book new_book(new_title, new_authors, new_dop);
    // return the insert method using new_book object
    return insert(new_book);
}

bool Library::remove(string new_title, string new_authors, string new_dop) {
    // setup - variable declaration and intialization
    bool book_exists = false;
    
    // iterate through vector elements to find the location of the entered book
    for (int iterator = 0; iterator < my_books.size(); iterator++){
        //boolean statements to check existence of specified boook in library
        book_exists = my_books[iterator].get_title() == new_title; // check for matching titles
        book_exists = book_exists && my_books[iterator].get_authors() == new_authors; // check for matching authors
        book_exists = book_exists && my_books[iterator].get_dop() == new_dop; // check for matching publication date
        
        // specified book exists
        if (book_exists){
            // swap the location of the entered book with the last book in the vector
            swap(my_books[iterator], my_books[my_books.size() - 1]);
            // remove the last element in the vector
            my_books.pop_back();
            return true;
        }
    }
    // specified book does not exist
    return false;
}

bool Library::remove(Book new_book) {
    // call getter to extract member attributes of specified book and call remove method
    return remove(new_book.get_title(), new_book.get_authors(), new_book.get_dop());
}

void Library::print() {
    // iterate through vector elements and output index of each book object and then print attributes of book
    for (int index = 0; index < my_books.size(); index++) {
        cout << "Book Index: " << index << endl;
        my_books[index].print();
    }
}
