#include <iostream>
#include <utility>
#include <vector>
#include <string>

void backtrack(std::string& s, int startIndex, std::vector<std::string>& result);

void permutation(std::string& s)
{
    std::vector<std::string> result {};
    int startIndex = 0;    
    backtrack(s, startIndex, result);
}

void backtrack(std::string& s, int startIndex, std::vector<std::string>& result)
{
    if (startIndex == s.size())
    {
        result.push_back(s);
        std::cout << s << "\n";
        return;
    }

    for (int i = startIndex; i < s.size(); ++i)
    {
        std::swap(s[startIndex], s[i]);
        backtrack(s, startIndex + 1, result);
        std::swap(s[startIndex], s[i]);
    }
}

int main()
{
    std::string s{"AAA"};
    permutation(s);
    std::cout << "\n";  
}