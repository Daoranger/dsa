#include "Library.h"

void Library::addBook(const std::string& title, const std::string& author)
{
    Book book(title, author, m_nextBookID++);
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
    for (const auto& user : m_users)
    {
        if (user->getName() == name)
        {
            return user->getID();
        }
    }

    return -1;
}

void Library::checkoutBook(int userid, int bookid)
{
    // assumed user id and book id are all unique

    // add book to user that matched userid
    for (auto& user : m_users)
    {
        if (user->getID() == userid)
        {
            Book* book = findBook(bookid);

            if (!book)
            {
                std::cout << "Couldn't find book\n";
                return;
            }

            user->userBorrow(*book);
            book->checkout();
        }
    }
}

void Library::returnBook(int userid, int bookid)
{
    // add book to user that matched userid
    for (auto& user : m_users)
    {
        if (user->getID() == userid)
        {
            user->userReturn(*findBook(bookid));

            // mark book as checked out in inventory
            for (auto& book : m_inventory)
            {
                if (book.getId() == bookid)
                {
                    book.returnBook();
                    return;
                }
            }
        }
    }
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
        << " (book id: " << book.getId() << ") "
        << "status: ";

        book.isAvailable() ? out << "available\n" : out << "not available\n";
    }

    return out;
}

