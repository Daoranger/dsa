#include <iostream>
#include <vector>

int main()
{
    // a vector for testing :D
    std::vector<int> v {1, 2, 3, 4, 5};

    // using iterator to modify each element
    for (std::vector<int>::iterator it  = v.begin(); it != v.end(); it++)
    {
        *it += 10;
    }

    // using iterator to traverse forward (read-only)
    for (std::vector<int>::const_iterator it  = v.cbegin(); it != v.cend(); it += 2)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // using iterator to modify the elements in the reverse order
    for (std::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
    {
        *it *= -1;
    }

    // using iteratator to traverse backward (reverse, read-only and I used auto :D)
    for (auto it  = v.crbegin(); it != v.crend(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";

}