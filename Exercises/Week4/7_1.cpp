#include <iostream>

int main()
{
    int scores[5] = { 11, 22, 33, 44, 55 };

    // 1) Loop through array
    // for (int i = 0; i < 5; ++i)
    // {
    //     std::cout << scores[i] << " of by " << (100 - scores[i]) << std::endl;
    // }

    // 2) Use constant for array size
    // const int NUMBER_OF_STUDENTS = 50;
    // int scores2[NUMBER_OF_STUDENTS];

    // 3) Array index out of range
    //std::cout << scores[6];

    // 4) Un-initialized arrays
    int arr[5] = {};

    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << " ";
    }
}