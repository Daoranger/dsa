#include <iostream>

void f(int i, int& j)
{
    i = (i + 5) / 2;
    j = j + i * 10;
}

int main()
{
    int i = 1;
    int j = 2;
    f(i, j);
    std::cout << "i = " << i << ", j=" << j;
}