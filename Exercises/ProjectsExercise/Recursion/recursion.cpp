#include <iostream>

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    std::cout << "Enter an integer n: ";
    int n;
    std::cin >> n;

    std::cout << "Factorial of " << n << " is: " << factorial(n) << "\n";
}