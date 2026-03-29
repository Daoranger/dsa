#include <iostream>
#include <vector>

int nthFibonacciNorm(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    return nthFibonacciNorm(n - 1) + nthFibonacciNorm(n - 2);
}

// Top-down approach
int nthFibonacciMem(int n, std::vector<int>& dp)
{
    if (n <= 1) return n;

    if (dp[n] == -1)
    {
        dp[n] = nthFibonacciMem(n - 1, dp) + nthFibonacciMem(n - 2, dp);
    }
    
    return dp[n];

}

int main()
{
    int n {};
    std::cout << "Enter n value: ";
    std::cin >> n;

    std::vector<int> dpVector(n + 1, -1);
    std::cout << nthFibonacciNorm(n) << "\n";
    std::cout << nthFibonacciMem(n, dpVector) << "\n";
    
}