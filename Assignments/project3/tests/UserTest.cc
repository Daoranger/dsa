#include <catch2/catch_test_macros.hpp>
#include "../User.h"

TEST_CASE("User ", "Book* findBook(id)")
{
    User u("Patel", 11);
    Book b("Hi", "hi", 1);
    u.userBorrow(b);

    std::cout << u;
}


