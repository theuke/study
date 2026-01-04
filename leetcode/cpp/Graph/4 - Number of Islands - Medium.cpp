#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>

using namespace std;

class Solution {
    enum
    {
        ROW = 0,
        COL
    };

    int num_rows;
    int num_cols;

    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& visited)
    {
        queue<vector<int>> q;
        visited[row][col] = true;
        q.push(vector<int>{row, col});

        while (!q.empty())
        {
            vector<int> n = q.front();
            row = n[ROW];
            col = n[COL];
            q.pop();

            if (row > 0 && grid[row - 1][col] == '1' && !visited[row - 1][col])
            {
                q.push({row - 1, col});
                visited[row - 1][col] = true;
            }

            if (row < num_rows - 1 && grid[row + 1][col] == '1' && !visited[row + 1][col])
            {
                q.push({row + 1, col});
                visited[row + 1][col] = true;
            }

            if (col > 0 && grid[row][col - 1] == '1' && !visited[row][col - 1])
            {
                q.push({row, col - 1});
                visited[row][col - 1] = true;
            }

            if (col < num_cols - 1 && grid[row][col + 1] == '1' && !visited[row][col + 1])
            {
                q.push({row, col + 1});
                visited[row][col + 1] = true;
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        num_rows = grid.size();
        num_cols = grid[0].size();

        vector<vector<bool>> visited(num_rows, vector<bool>(num_cols, false));
        
        int num_islands = 0;

        for (int i = 0; i < num_rows; ++i)
        {
            for (int j = 0; j < num_cols; ++j)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    ++num_islands;
                    bfs(i, j, grid, visited);
                }
            }
        }

        return num_islands;
    }
};

int main()
{
    // vector<vector<char>> grid
    // {
    //     {'1','1','1','1','0'},
    //     {'1','1','0','1','0'},
    //     {'1','1','0','0','0'},
    //     {'0','0','0','0','0'}
    // };

    // int answer = 1;

    // vector<vector<char>> grid
    // {
    //     {'1','1','0','0','0'},
    //     {'1','1','0','0','0'},
    //     {'0','0','1','0','0'},
    //     {'0','0','0','1','1'}
    // };

    // int answer = 3;

    vector<vector<char>> grid
    {
        {'1','1','1'},
        {'0','1','0'},
        {'1','1','1'}
    };

    int answer = 1;

    Solution solution;
    int my_answer = solution.numIslands(grid);

    cout << "answer    = " << answer << endl;
    cout << "my_answer = " << my_answer << endl;
}