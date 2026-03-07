#include <iostream>

int main()
{
    int x = 0;
    if (x = 0)  // evaulate to 0 and 0 is false in C++, non-zero is true
    {
        std::cout << "IT IS ZERO\n";
    }
    else
    {
        std::cout << "IT IS NOT ZERO\n";
    }
}