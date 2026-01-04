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
private:
    const int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    int bfs(int row, int col, vector<vector<int>>& grid)
    {
        int area = 1;
        grid[row][col] = 0;
        queue<pair<int, int>> q;
        q.push({row, col});

        while(!q.empty())
        {
            pair<int, int> p = q.front();
            row = p.first;
            col = p.second;
            q.pop();

            // Check across the four directions whether we should
            // should explore the node or not.
            for (int i = 0; i < sizeof(dir) / sizeof(dir[0]); ++i)
            {
                int adj_row = row + dir[i][0];
                int adj_col = col + dir[i][1];

                if (adj_row >= 0 && adj_row < grid.size() && adj_col >= 0 && adj_col < grid[0].size() && grid[adj_row][adj_col])
                {
                    grid[adj_row][adj_col] = 0;
                    ++area;
                    q.push({adj_row, adj_col});
                }
            }
        }

        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> my_grid = grid;

        int largest_area = 0;

        for (int row = 0; row < my_grid.size(); ++row)
            for (int col = 0; col < my_grid[0].size(); ++col)
                if (my_grid[row][col])
                    largest_area = max(largest_area, bfs(row, col, my_grid));
        
        return largest_area;
    }
};

int main()
{
    vector<vector<int>> grid { {0, 1}, {1, 2}, {2, 4} };
    int answer = 6;

    Solution solution;
    int my_answer = solution.maxAreaOfIsland(grid);

    cout << "answer    = " << answer << endl;
    cout << "my_answer = " << my_answer << endl;
}