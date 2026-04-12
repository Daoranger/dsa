#include <iostream>
#include <vector>

int fibMemo(int n, std::vector<int>& memo)
{
    // base cases
    if (n <= 1) return n;

    if (memo[n] == -1)
        memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);

    return memo[n];
}

int main()
{
    std::cout << "Enter a value for n: ";
    int n;
    std::cin >> n;

    std::vector<int> dp(n + 1, -1);
    std::cout << "FibMemo of " << n << " is: " << fibMemo(n, dp) << "\n";
}