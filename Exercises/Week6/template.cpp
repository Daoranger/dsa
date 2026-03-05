#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

template <typename Ta, typename Tb>
int max(Ta x, Tb y)
{
    return (x < y) ? y : x;
}

int main()
{

    auto result = max(1, 2.0);
    std::cout << result << "\n";
    std::cout << typeid(result).name() << "\n";
}