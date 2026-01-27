#include <iostream>

int main()
{
    // int x { 11 };
    // std::cout << &x << std::endl;
    //
    // {
    //     std::cout << &x << std::endl;
    //     int x { 99 };
    //     std::cout << &x << std::endl;
    // }
    //
    // std::cout << &x << std::endl;

    int next { 2 };
    int product { 1 };

    while (next <= 5)
    {
        product *= next;
        ++next;
    }

    std::cout << "product=" << product << '\n';

}
