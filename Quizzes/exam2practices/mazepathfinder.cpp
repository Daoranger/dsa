#include <iostream>
#include <vector>

bool foundPath(const std::vector<std::vector<int>>& maze, int currRow, int currCol)
{
    bool found = false;
    int goalRow = maze.size() - 1;
    int goalCol = maze[0].size() - 1;

    if (currRow > goalRow || currCol > goalCol) return false;

    if (maze[currRow][currCol] == 1) return false;
    
    if (currRow == goalRow && currCol == goalCol)
    {
        return true;
    }
    else
    {
        if (foundPath(maze, currRow + 1, currCol))  // go down to check
        {
            found = true;
        }
        else if (foundPath(maze, currRow, currCol + 1)) // if go down doesn't work, go right
        {
            found = true; 
        }
        else
        {
            found = false;      // if both down and right doesn't work, deadend;
        }
    }

    return found;
}

int main()
{
    std::vector<std::vector<int>> maze
    {
        {0, 0, 0},
        {1, 0, 0},
        {1, 1, 0}
    };

    std::cout << ((foundPath(maze, 0, 0)) ? "There is a path\n" : "There is no path\n");

    return 0;
}