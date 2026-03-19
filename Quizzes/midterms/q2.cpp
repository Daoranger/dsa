#include <iostream>
#include <vector>

std::vector<int> findIntersection(const std::vector<int>& v1, const std::vector<int>& v2)
{
    std::vector<int> result {};  // vector store intersection elements

    for (int i = 0; i < v1.size(); ++i)
    {
        std::vector<int>iterator it = std::find(result.begin(), result.end(), v1[i]);
        if (it != v1.end())
        {
            result.push_back(v1[i]);
        }
    }

    for (int i = 0; i < v2.size(); ++i)
    {
        std::vector<int>iterator it = std::find(result.begin(), result.end(), v2[i]);
        if (it != v2.end())
        {
            result.push_back(v2[i]);
        }
    }

    return result;
}