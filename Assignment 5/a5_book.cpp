#include "a5_book.hpp"

Book::Book() :
        book_title("n/a"),
        book_authors("n/a"),
        date_of_publication("n/a") {}

Book::Book(string new_title) :
        book_title(new_title),
        book_authors("n/a"),
        date_of_publication("n/a") {}

Book::Book(string new_title, string new_authors) :
        book_title(new_title),
        book_authors(new_authors),
        date_of_publication("n/a") {}

Book::Book(string new_title, string new_authors, string new_dop) :
        book_title(new_title),
        book_authors(new_authors),
        date_of_publication(new_dop) {}

void Book::print() {
    // output each attribute of book
    cout << "Title: " << book_title << endl;
    cout << "Authors: " <<book_authors << endl;
    cout << "Date of Publication: " << date_of_publication << endl << endl;
}
    
string Book::get_title() {
    return book_title;
}

string Book::get_authors() {
    return book_authors;
}

string Book::get_dop() {
    return date_of_publication;
}
