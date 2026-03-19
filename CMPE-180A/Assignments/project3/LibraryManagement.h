/**
 * Author: Hoang Nguyen
 * 
 */
#ifndef LIBRARYMANAGEMENT_H
#define LIBRARYMANAGEMENT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Book
{
public:
    Book(std::string t, std::string a, int id);
    Book(const Book& other);
    ~Book();
    void checkout();
    void returnBook();
    bool isAvailable() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getId() const;
    bool getCheckedOutStatus() const;
    bool operator== (const Book& book) const;

private:
    std::string m_title;
    std::string m_author;
    int m_id;
    bool m_checkedOut;
};

class User
{
public:
    explicit User(std::string name);
    void borrow(Book& book);
    void returnBook(Book& book);
    friend std::ostream& operator<<(std::ostream& out, const User& user);
    std::string getName() const;
    std::size_t getBorrowBooksSize() const;

private:
    std::string m_name;
    std::vector<Book*> m_borrowedBooks;
};

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
    std::vector<Book> m_inventory;
    std::vector<User*> m_users;
};

#endif