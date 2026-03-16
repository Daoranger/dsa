#ifndef USER_H
#define USER_H

#include "Book.h"
#include <iostream>
#include <string>
#include <vector>

class User
{
public:
    User(std::string name);
    void userBorrow(Book& book);
    void userReturn(Book& book);
    friend std::ostream& operator<<(std::ostream& out, const User& user);

private:
    std::string m_name;
    std::vector<Book*> m_borrowedBooks;

};

#endif