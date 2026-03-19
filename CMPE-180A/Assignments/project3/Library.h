#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "User.h"
#include <string>
#include <iostream>

class Library
{
public:
    void addBook(const std::string& title, const std::string& author);
    void addUser(User& user);
    Book* findBook(int id);
    int getBookIdByTitle(std::string title);
    int getUserIdByName(std::string name);
    void checkoutBook(int userid, int bookid);
    void returnBook(int userid, int bookid);
    friend std::ostream& operator<<(std::ostream& out, const Library& library);

private:
    int m_nextBookID{1};
    int m_nextUserID{1};
    std::vector<Book> m_inventory;
    std::vector<User*> m_users;
};

#endif