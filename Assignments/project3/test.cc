#include <catch2/catch_test_macros.hpp>
#include "Book.h"

TEST_CASE("Book constructor/getters", "[constructor/getters]")
{
    Book book("Crime and Punishment", "Fyodor Dostoevsky", 11);
    REQUIRE(book.getTitle() == "Crime and Punishment");
    REQUIRE(book.getAuthor() == "Fyodor Dostoevsky");
    REQUIRE(book.getId() == 11);
}