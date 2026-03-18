#include <catch2/catch_test_macros.hpp>
#include "../Book.h"
#include "../User.h"
#include "../Library.h"
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
    User u("Patel", 11);
    u.userBorrow(b1);
    u.userBorrow(b2);
    REQUIRE(u.getBorrowBooksSize() == 2);
}

TEST_CASE("Test 4")
{
    Book b1("A", "B", 101);
    User u("Patel", 11);
    u.userBorrow(b1);

    std::ostringstream out;
    out << u;

    REQUIRE(out.str() == "Patel's list of borrowed books:\n"
                         "1. \"A\" by B (book id: 101)\n");
}

TEST_CASE("Test 5")
{
    Library lib;
    lib.addBook("Art of the Deal", "DJ Trump");
    REQUIRE(lib.getBookIdByTitle("Art of the Deal") == 1);
}

TEST_CASE("Test 6")
{
    Library lib;
    User u("Patel", 99);
    lib.addUser(u);
    REQUIRE(lib.getUserIdByName("Patel") == 99);
}

TEST_CASE("Test 7")
{
    Library lib;
    lib.addBook("Art of the Deal", "DJ Trump");
    User u("Patel", 99);
    lib.addUser(u);
    lib.checkoutBook(99, 1);
    REQUIRE(lib.findBook(1)->getCheckedOutStatus() == true);
    REQUIRE(u.getBorrowBooksSize() == 1);
}

TEST_CASE("Test 8")
{
    Library lib;
    lib.addBook("Art of the Deal", "DJ Trump");
    User u("Patel", 99);
    lib.addUser(u);
    lib.checkoutBook(99, 1);
    lib.returnBook(99, 1);
    REQUIRE(lib.findBook(1)->getCheckedOutStatus() == false);
    REQUIRE(u.getBorrowBooksSize() == 0);
}

TEST_CASE("Test 9")
{
    Library lib;
    lib.addBook("Art of the Deal", "DJ Trump");
    User u("Patel", 99);
    lib.addUser(u);
    lib.checkoutBook(99, 1);

    std::ostringstream out;
    out << lib;

    REQUIRE(out.str() == "Library's inventory:\n"
                         "1. \"Art of the Deal\" by DJ Trump (book id: 1), status: not available\n");
}





