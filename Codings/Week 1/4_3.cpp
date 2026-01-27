#include <iostream>

int sumThree(int, int, int);

int sumThree(int x, int y, int z)
{
    return x + y + z;
}

double average(int x, double y)
{
    return static_cast<double>((x + y) / 2);
}

int main()
{
    std::cout << "sumThree=" << sumThree(11,22,33) << '\n';
    std::cout << "average=" << average(11, 22.5) << '\n';
}

