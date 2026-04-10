#include <iostream>
#include <vector>

int fibMemo(int n, std::vector<int>& memo)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    if (memo[n] != -1)
    {
        return memo[n];
    }
    
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