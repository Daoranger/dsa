#include <iostream>
#include <string>

template <typename T>
T max(T a, T b)
{
    return (a < b) ? b : a;
}

int main()
{
    std::cout << max(1, 1) << "\n";     // expect 1
    std::cout << max(3, 7) << "\n";     // expect 7
    std::cout << max(10, 2) << "\n";    // expect 10
    std::cout << max(-10, -2) << "\n";  // expect -2
    std::cout << max(2.11, 2.111) << "\n";  // expect 2.111
    std::cout << max<int>(2.11, 2) << "\n";  // expect 2.111
    std::cout << max<double>(2.11, 2) << "\n";  // compile error
    std::cout << max<int>('c', 2) << "\n";
}