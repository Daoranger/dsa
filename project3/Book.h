#ifndef BOOK_H
#define BOOK_H

class Book
{
public:
	Book(std::string t, std::string a, int id);
	Book(const Book& other);
	~Book();
	void checkout();
	Book returnBook();
	bool isAvailable();
	std::string getTitle();
	int getId();
	bool operator== (const Book& book);

private:
	std::string title;
	std::string author;
	int id;
	bool checkedOut;


	hehahah
};

#endif
