#include "Book.h"
#include "User.h"
#include <iostream>

int main()
{
	Book book1("Dez", "Hoang Nguyen", 11);
	Book book2("Gagua", "Alvin Tran", 12);

	User hoang("Hoang Nguyen");
	hoang.userBorrow(book1);
	hoang.userBorrow(book2);
	//hoang.userReturn(book1);

	std::cout << hoang;
	return 0;
}
