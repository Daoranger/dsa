#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <iostream

class Library
{
public:
    void addBook(const Book& book);
    void addUser(const User& user);
    Book* findBook(int id);
    int getBookIdByTitle(std::string title);
    int getUserIdByName(std::string name);
    void checkoutBook(int userid, int bookid);
    void returnBook(int userid, int bookid);
    friend std::ostream& operator<<(std::ostream& out, const std::vector<Book>& inv);

private:
    std::vector<Book> inventory;
    std::vector<User> users;

};

#endif