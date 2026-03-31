#include "HugeNumber.h"
#include <iostream>

int main()
{
    HugeNumber hn1(std::string("999999999999"));
    HugeNumber hn2(std::string("1"));

    HugeNumber result = hn1 + hn2;

    std::cout << result << "\n";
}