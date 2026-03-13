#include "Library.h"

void Library::addBook(const Book& book)
{
    inventory.push_back(book);
}

void Library::addUser(const User& user)
{
    users.push_back(user);
}

Book* Library::findBook(int id)
{
    for (const auto& book : inventory)
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
    for (const auto& book : inventory)
    {
        if (book.getTitle() == title)
        {
            return book.id;
        }
    }
}

int Library::getUserIdByName(std::string name)
{
    for (const auto& user : user)
    {
        if (user.getTitle() == title)
        {
            return book.id;
        }
    }
}

void Library::checkoutBook(int userid, int bookid)
{
    //users[getUserIdByName(userid)].borrow()
}