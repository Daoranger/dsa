#include <iostream>
#include <vector>

bool foundPath(const std::vector<std::vector<int>>& maze, int currRow, int currCol)
{;
    int goalRow = maze.size() - 1;
    int goalCol = maze[0].size() - 1;

    // if out of bound or cell is blocked
    if (currRow > goalRow || currCol > goalCol || maze[currRow][currCol] == 1) return false;
    
    // base case: if we reached the end
    if (currRow == goalRow && currCol == goalCol)
    {
        return true;
    }
    
    // general case
    if (foundPath(maze, currRow + 1, currCol))  // go down to check
    {
        return true;
    }
    else if (foundPath(maze, currRow, currCol + 1)) // if go down doesn't work, go right
    {
        return true; 
    }

    // deadend
    return false;
}

int main()
{
    std::vector<std::vector<int>> maze
    {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1},
        {0, 1, 0, 0}
    };

    std::cout << ((foundPath(maze, 0, 0)) ? "There is a path\n" : "There is no path\n");

    return 0;
}