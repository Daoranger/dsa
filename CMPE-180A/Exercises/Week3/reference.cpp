#include <iostream>
#include <cassert>

void show_result(double f_degrees, double c_degrees)
{
    std::cout << f_degrees << " degree F is equivalent to "
              << c_degrees << " degrees Celsius\n";

    return;
}

void swapRef(int& a, int& b)
{
    int temp = b;
    b = a;
    a = temp;
}

void swapValue(int a, int b)
{
    int temp = b;
    b = a;
    a = temp;
}

void zero_both(int&a, int& b)
{
    a = 0;
    b = 0;
}

double newton_sqrt(double n, int num_iterations)
{
    double answer = 1;
    int i = 0;

    assert((n>0) && (num_iterations>0));
    while (i < num_iterations)
    {
        answer = 0.5 * (answer + n / answer);
        i++;
    }

    return answer;
}

int main()
{
    //show_result(10.0, 20.0);

    // int x = 11;
    // int y = 99;
    //
    // swapRef(x, y);
    // std::cout << "x=" << x << " y=" << y << '\n';
    //
    // swapValue(x, y);
    // std::cout << "x=" << x << " y=" << y << '\n';
    //
    // zero_both(x, y);
    // std::cout << "x=" << x << " y=" << y << '\n';

    std::cout << "result=" << newton_sqrt(1, 0);
}