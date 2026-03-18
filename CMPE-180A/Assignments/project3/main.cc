#include "Book.h"
#include "User.h"
#include "Library.h"
#include <iostream>

int main()
{
	Library lib;

	lib.addBook("Art of the Deal", "DJ Trump");

	lib.addBook("C++", "Deitel");

	User u("Patel", 11);

	lib.addUser(u);

	lib.checkoutBook(lib.getUserIdByName("Patel"), lib.getBookIdByTitle("Art of the Deal"));

	std::cout << u; // print list of books borrowed by user

	std::cout << lib; // print inventory of books indicating those that are out
}
