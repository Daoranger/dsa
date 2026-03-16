#include "Book.h"

Book::Book(std::string t, std::string a, int id)
	: m_title{t}
	, m_author{a}
	, m_id{id}
	
{
	std::cout << "Book(t, a, id) called\n";
}

Book::Book(const Book& other)
	: m_title{other.m_title}
	, m_author{other.m_author}
	, m_id{other.m_id}
{	
	// Debug
	std::cout << "Copy constructor called\n";
}

Book::~Book()
{
	// Debug
	std::cout << "Destructor called\n";
}

void Book::checkout()
{
	m_checkedOut = true;
}

void Book::returnBook()
{
	m_checkedOut = false;
}

bool Book::isAvailable()
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

bool Book::operator==(const Book& book)
{
	return (m_id == book.m_id);
}