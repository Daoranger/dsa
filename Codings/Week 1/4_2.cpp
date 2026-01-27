#include <iostream>
#include <cmath>

// Random number genreaiton
#include <cstdlib>
#include <ctime>

int randomInRange(const int lower, const int upper)
{
    // range is how many possible results there are
    int range = upper - lower + 1;

    // rand() give int from 0 to RAND_MAX
    int rand = std::rand() % range + lower;
    return rand;
}

int main()
{
    // Random Number Generation
    // double x = std::sqrt(12.0);
    // std::cout << "x=" << x << '\n';
    //
    // double y = std::abs(-8);
    // std::cout << "y=" << y << '\n';
    //
    // std::srand(std::time(nullptr));
    //
    // std::cout << "Enter lower and upper bounds: ";
    // int lower, upper;
    // std::cin >> lower >> upper;
    //
    // for (int i = 0; i < 10; ++i)
    //     std::cout << "random=" << randomInRange(lower, upper) << '\n';

    // Type Casting
    // int a { 11 };
    // int b { 2 };
    // double c { 0 };
    //
    // c = static_cast<double>(a) / static_cast<double>(b);
    //
    // std::cout << "c=" << c << '\n';

    // 4.2 Conclusion

    double d = 11 / 2;          // this will print 5
    std::cout << "d=" << d << '\n';

    std::cout << pow(2,3) << '\n'; // 8
    std::cout << fabs(-3.5) << '\n';
    std::cout << sqrt(pow(3,2)) << '\n';
    std::cout << 7 / abs(-2) << '\n';
    std::cout << ceil(5.8) << '\n';
    std::cout << floor(5.8) << '\n';
}