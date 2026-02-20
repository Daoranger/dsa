#include <iostream>
#include <string>
#include <fstream>

namespace Hoang
{
    void printHoang()
    {
        std::cout << "Hoang\n";
    }
}

int avg(int a, int b = 0)
{
    return (a + b) / 2;
}

int avg(int a)
{
    return a;
}

int main()
{
    // 1. Use namespace prefix;
    //Hoang::printHoang();

    // 2. using keyword
    //using Hoang::printHoang;
    //printHoang();

    // 3. using whole namespace
    // using namespace Hoang;
    // printHoang();
    //
    // std::cout << avg(5) << '\n';

    std::string s;
    std::ifstream if_stream;

    if_stream.open("hi.txt");

    if (!if_stream)
    {
        std::cerr << "Can't open file hi.txt\n";
    }

    while (if_stream >> s)
    {
        std::cout << s;
    }

    if_stream.close();

}