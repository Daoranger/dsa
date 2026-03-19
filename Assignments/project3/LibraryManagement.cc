/**
 * LibraryManagement.cc
 *
 * Author: Hoang Nguyen
 *
 * Date created: 3/13/2026
 * Last modified: 3/18/2026
 *
 * Description: This file included the implementations of 3 classes: Book, User and Library
 *
 */

#include "LibraryManagement.h"

Book::Book(std::string t, std::string a, int id)
    : m_title(t)
    , m_author(a)
    , m_id(id)
    , m_checkedOut(false)
{
}

Book::Book(const Book& other)
    : m_title(other.m_title)
    , m_author(other.m_author)
    , m_id(other.m_id)
    , m_checkedOut(other.m_checkedOut)
{
}

Book::~Book()
{
}

void Book::checkout()
{
    if (isAvailable())
    {
        m_checkedOut = true;
    }
}

void Book::returnBook()
{
    m_checkedOut = false;
}

bool Book::isAvailable() const
{
    return !m_checkedOut;
}

std::string Book::getTitle() const
{
    return m_title;
}

std::string Book::getAuthor() const
{
    return m_author;
}

int Book::getId() const
{
    return m_id;
}

bool Book::getCheckedOutStatus() const
{
    return m_checkedOut;
}

bool Book::operator==(const Book& book) const
{
    return (m_id == book.m_id);
}

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
    out << user.m_name << "'s " << "list of borrowed books:\n";
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

std::size_t User::getBorrowBooksSize() const
{
    return m_borrowedBooks.size();
}

void Library::addBook(const std::string& title, const std::string& author)
{
    int id = static_cast<int>(m_inventory.size());
    Book book(title, author, id);
    m_inventory.push_back(book);
}

void Library::addUser(User& user)
{
    m_users.push_back(&user);
}

Book* Library::findBook(int id)
{
    for (auto& book : m_inventory)
    {
        if (book.getId() == id)
        {
            return &book;
        }
    }

    return nullptr;
}

int Library::getBookIdByTitle(std::string title)
{
    for (const auto& book : m_inventory)
    {
        if (book.getTitle() == title)
        {
            return book.getId();
        }
    }

    return -1;
}

int Library::getUserIdByName(std::string name)
{
    for (std::size_t i = 0; i < m_users.size(); ++i)
    {
        if (m_users[i]->getName() == name)
        {
            return static_cast<int>(i);
        }
    }

    return -1;
}

void Library::checkoutBook(int userid, int bookid)
{
    // if invalid user id
    if (userid < 0 || userid >= static_cast<int>(m_users.size()))
    {
        return;
    }

    Book* book = findBook(bookid);
    if (!book)
    {
        return;
    }

    if (!book->isAvailable())
    {
        return;
    }

    book->checkout();
    m_users[userid]->borrow(*book);
}

void Library::returnBook(int userid, int bookid)
{
    // if invalid user id
    if (userid < 0 || userid >= static_cast<int>(m_users.size()))
    {
        return;
    }

    Book* book = findBook(bookid);
    if (!book)
    {
        return;
    }

    m_users[userid]->returnBook(*book);
    book->returnBook();
}

std::ostream& operator<<(std::ostream& out, const Library& library)
{
    int counter {1};
    out << "Library's inventory:\n";
    for (const auto& book : library.m_inventory)
    {
        out << counter++ << ". "
        << "\"" << book.getTitle() << "\" by "
        << book.getAuthor()
        << " (book id: " << book.getId() << ")"
        << ", status: ";

        book.isAvailable() ? out << "available\n" : out << "not available\n";
    }

    return out;
}





