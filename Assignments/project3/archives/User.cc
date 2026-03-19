#include "../User.h"
#include <algorithm>

User::User(std::string name)
    : m_name(name)
{
}

void User::borrow(Book& book)
{
    m_borrowedBooks.push_back(&book);
}

void User::returnBook(Book& book)
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
    out << user.m_name << "'s (user id: " << user.m_id << ") list of borrowed books:\n";
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

void User::setID(int id)
{
    m_id = id;
}

std::size_t User::getBorrowBooksSize() const
{
    return m_borrowedBooks.size();
}




