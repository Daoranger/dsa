#include <catch2/catch_test_macros.hpp>
#include "../Library.h"

TEST_CASE("Library find book", "Book* findBook(id)")
{
    Library lib;
    lib.addBook("Art of the Deal", "DJ Trump");
    int id = lib.getBookIdByTitle("Art of the Deal");
    REQUIRE(id == 1);
}

TEST_CASE("getUserIdByName", "Test 2")
{
    Library lib;
    User u("Patel", 11);
    lib.addUser(u);

    int id = lib.getUserIdByName("Patel");
    REQUIRE(id == 11);
}

TEST_CASE("findBook", "Test 3")
{
    Library lib;
    lib.addBook("Art of the Deal", "DJ Trump");
    Book& book = *lib.findBook(1);

    REQUIRE(book.getTitle() == "Art of the Deal");
    REQUIRE(book.getAuthor() == "DJ Trump");
    REQUIRE(book.getId() == 1);
}

