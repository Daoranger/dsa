#include "User.h"
#include <algorithm>

User::User(std::string name, int id)
    : m_name(name)
    , m_id(id)
{
}

void User::userBorrow(Book& book)
{
    m_borrowedBooks.push_back(&book);
}

void User::userReturn(Book& book)
{
    auto book_it = std::find(m_borrowedBooks.begin(), m_borrowedBooks.end(), &book);
    if (book_it != m_borrowedBooks.end())
    {
        m_borrowedBooks.erase(book_it);
    }
}

std::ostream& operator<<(std::ostream& out, const User& user)
{
    int counter { 1 };
    out << user.m_name << "'s list of borrowed books: \n";
    for (const auto& book : user.m_borrowedBooks)
    {
        out << counter++ << ". " << "\"" << book->getTitle() << "\" by " << book->getAuthor() << " (book id: " << book->getId() << ")\n";
    }
    return out;
}

std::string User::getName() const
{
    return m_name;
}

int User::getID() const
{
    return m_id;
}




