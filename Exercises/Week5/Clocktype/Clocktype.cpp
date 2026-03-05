//
// Created by hoang on 2/26/2026.
//

#include <iostream>

class Clocktype
{
public:
    Clocktype();
    Clocktype(int x);

};

Clocktype::Clocktype()
{
    std::cout << "Clocktype() was called\n";
}

Clocktype::Clocktype(int x)
{
    std::cout << "Clocktype(int x) was called\n";
}


int main()
{
    Clocktype c = 1;
}
