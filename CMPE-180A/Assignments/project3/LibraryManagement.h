#ifndef LIBRARYMANAGEMENT_H
#define LIBRARYMANAGEMENT_H

#include <iostream>
#include <string>
#include <vector>

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



#endif