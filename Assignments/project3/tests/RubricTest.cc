#include <catch2/catch_test_macros.hpp>
#include "../LibraryManagement.h"
#include <sstream>

TEST_CASE("Test 1")
{
    Book b("The Hobbit", "J.R.R. Tolkien", 101);
    REQUIRE(b.getTitle() == "The Hobbit");
    REQUIRE(b.isAvailable() == true);
}

TEST_CASE("Test 2")
{
    Book b1("A", "B", 101);
    Book b2("C", "D", 101);
    REQUIRE(b1 == b2);
}

TEST_CASE("Test 3")
{
    Book b1("A", "B", 101);
    Book b2("C", "D", 101);
    User u("Patel");
    u.borrow(b1);
    u.borrow(b2);
    REQUIRE(u.getBorrowBooksSize() == 2);
}

TEST_CASE("Test 4")
{
    Book b1("A", "B", 101);
    User u("Patel");
    u.borrow(b1);

    std::ostringstream out;
    out << u;

    REQUIRE(out.str() == "Patel's list of borrowed books:\n"
                         "1. \"A\" by B (book id: 101)\n");
}

TEST_CASE("Test 5")
{
    Library lib;
    lib.addBook("Art of the Deal", "DJ Trump");
    REQUIRE(lib.getBookIdByTitle("Art of the Deal") == 0);
}

TEST_CASE("Test 6")
{
    Library lib;
    User u("Patel");
    lib.addUser(u);
    REQUIRE(lib.getUserIdByName("Patel") == 0);
}

TEST_CASE("Test 7")
{
    Library lib;
    lib.addBook("Art of the Deal", "DJ Trump");
    User u("Patel");
    lib.addUser(u);
    lib.checkoutBook(0, 0);
    REQUIRE(lib.findBook(0)->getCheckedOutStatus() == true);
    REQUIRE(u.getBorrowBooksSize() == 1);
}

TEST_CASE("Test 8")
{
    Library lib;
    lib.addBook("Art of the Deal", "DJ Trump");
    User u("Patel");
    lib.addUser(u);
    lib.checkoutBook(0, 0);
    lib.returnBook(0, 0);
    REQUIRE(lib.findBook(0)->getCheckedOutStatus() == false);
    REQUIRE(u.getBorrowBooksSize() == 0);
}

TEST_CASE("Test 9")
{
    Library lib;
    lib.addBook("Art of the Deal", "DJ Trump");
    User u("Patel");
    lib.addUser(u);
    lib.checkoutBook(0, 0);

    std::ostringstream out;
    out << lib;

    REQUIRE(out.str() == "Library's inventory:\n"
                         "1. \"Art of the Deal\" by DJ Trump (book id: 0), status: not available\n");
}





