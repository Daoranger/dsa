#ifndef USER_H
#define USER_H

#include "Book.h"
#include <iostream>
#include <string>
#include <vector>

class User
{
public:
    explicit User(std::string name);
    void userBorrow(Book& book);
    void userReturn(Book& book);
    friend std::ostream& operator<<(std::ostream& out, const User& user);
    std::string getName() const;
    int getID() const;
    void setID(int id);
    std::size_t getBorrowBooksSize() const;

private:
    std::string m_name;
    int m_id;
    std::vector<Book*> m_borrowedBooks;

};

#endif