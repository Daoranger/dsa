#include <catch2/catch_test_macros.hpp>
#include "Book.h"

TEST_CASE("Book constructor/getters", "[constructor/getters]")
{
    Book book("Crime and Punishment", "Fyodor Dostoevsky", 111);
    REQUIRE(book.getTitle() == "Crime and Punishment");
    REQUIRE(book.getAuthor() == "Fyodor Dostoevsky");
    REQUIRE(book.getId() == 111);
}

TEST_CASE("Book copy constructor", "[copy constructor]")
{
    Book book("Crime and Punishment", "Fyodor Dostoevsky", 111);
    Book bookCopy = book;
    REQUIRE(bookCopy.getTitle() == "Crime and Punishment");
    REQUIRE(bookCopy.getAuthor() == "Fyodor Dostoevsky");
    REQUIRE(bookCopy.getId() == 111);
}

TEST_CASE("Book checkout and is avaiable check" "[checkout()/isAvailable()]")
{
    Book book("Crime and Punishment", "Fyodor Dostoevsky", 111);
    book.checkout();
    REQUIRE(book.isAvailable() == false);
}

TEST_CASE("Book return" "[returnBook()]")
{
    Book book("Crime and Punishment", "Fyodor Dostoevsky", 111);
    book.checkout();
    book.returnBook();
    REQUIRE(book.isAvailable() == true);
}

TEST_CASE("Books ids matched" "[operator==()]")
{
    Book book("Crime and Punishment", "Fyodor Dostoevsky", 111);
    Book bookCopy = book;
    REQUIRE(book == bookCopy);
}

TEST_CASE("Books ids do not match" "[operator==()]")
{
    Book book1("Crime and Punishment", "Fyodor Dostoevsky", 111);
    Book book2("The Brothers Karamazov", "Fyodor Dostoevsky", 112);
    REQUIRE(!(book1 == book2));
}