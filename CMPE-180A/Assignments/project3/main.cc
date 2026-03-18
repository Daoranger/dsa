#include "Book.h"
#include "User.h"
#include "Library.h"
#include <iostream>

int main()
{
	Library lib;

	lib.addBook("Art of the Deal", "DJ Trump");
	lib.addBook("C++", "Deitel");
	lib.addBook("Crime and Punishment", "Fyodor Dostoevsky");

	User u("Patel");

	lib.addUser(u);

	lib.checkoutBook(lib.getUserIdByName("Patel"), lib.getBookIdByTitle("Art of the Deal"));
	//lib.returnBook(lib.getUserIdByName("Patel"), lib.getBookIdByTitle("Art of the Deal"));
	lib.checkoutBook(lib.getUserIdByName("Patel"), lib.getBookIdByTitle("Crime and Punishment"));

	std::cout << u; // print list of books borrowed by user

	std::cout << "\n";

	std::cout << lib; // print inventory of books indicating those that are out
}
