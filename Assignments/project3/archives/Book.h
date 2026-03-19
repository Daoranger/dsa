#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

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
	bool operator== (const Book& book);

private:
	std::string m_title;
	std::string m_author;
	int m_id;
	bool m_checkedOut;
};

#endif
