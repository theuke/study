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
    typedef enum
    {
        OCEAN_PACIFIC = 0,
        OCEAN_ATLANTIC,
        OCEAN_MAX
    } ocean_t;

    typedef struct Node_t
    {
        bool oceans[OCEAN_MAX];
        vector<Node_t*> children;
    } Node_t;

    void bfs(Node_t *root, vector<vector<int>>& heights, ocean_t ocean)
    {
        queue<Node_t *> q;
        q.push(root);

        while (!q.empty())
        {
            Node_t *node = q.front();
            q.pop();

            for (int i = 0; i < node->children.size(); ++i)
            {
                if (!node->children[i]->oceans[ocean])
                {
                    node->children[i]->oceans[ocean] = true;
                    q.push(node->children[i]);
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // For this problem, we must first break it down into two
        // distinct subproblems: a) Can rain flow from the indicated
        // cell into pacific ocean and b) Can rain flow form  the indicated
        // cell into the atlantic ocean. Then, we take the intersection of
        // these two solution which should tell us whether rain can flow
        // from the indicated cell into both the pacific and atlantic oceans.

        // The question here then is how can one figure out whether rain
        // can flow from a given cell to the edge of the grid? Initially
        // I would say that one  can do some dynamic programming here.
        // The idea is to start in one corner of the grid and keep
        // progressing until the other corner is reached.

        int num_rows = heights.size();
        int num_cols = heights[0].size();

        vector<vector<Node_t>> grid(num_rows, vector<Node_t>(num_cols));

        // Fill out the nodes.
        for (int i = 0; i < num_rows; ++i)
        {
            for (int j = 0; j < num_cols; ++j)
            {
                if (i == 0 || j == 0)
                    grid[i][j].oceans[OCEAN_PACIFIC] = true;
                else
                    grid[i][j].oceans[OCEAN_PACIFIC] = false;
                
                if (i == num_rows - 1 || j == num_cols - 1)
                    grid[i][j].oceans[OCEAN_ATLANTIC] = true;
                else
                    grid[i][j].oceans[OCEAN_ATLANTIC] = false;

                if (i > 0 && heights[i][j] <= heights[i - 1][j])
                    grid[i][j].children.push_back(&grid[i - 1][j]);

                if (i < num_rows - 1 && heights[i][j] <= heights[i + 1][j])
                    grid[i][j].children.push_back(&grid[i + 1][j]);

                if (j > 0 && heights[i][j] <= heights[i][j - 1])
                    grid[i][j].children.push_back(&grid[i][j - 1]);

                if (j < num_cols - 1 && heights[i][j] <= heights[i][j + 1])
                    grid[i][j].children.push_back(&grid[i][j + 1]);
            }
        }

        for (int i = 1; i < num_rows; ++i)
            bfs(&grid[i][0], heights, OCEAN_PACIFIC);
        
        for (int j = 1; j < num_cols; ++j)
            bfs(&grid[0][j], heights, OCEAN_PACIFIC);

        for (int i = num_rows - 1; i >= 0; --i)
            bfs(&grid[i][num_cols - 1], heights, OCEAN_ATLANTIC);
        
        for (int j = num_cols - 1; j >= 0; --j)
            bfs(&grid[num_rows - 1][j], heights, OCEAN_ATLANTIC);

        vector<vector<int>> pacific_and_atlantic;

        // Take the intersection of the pacific and atlantic rain fall grids. This simply means
        // to iterate over both grids in lock step and record the indicies of the cells which
        // have both rain flows marked as true.
        for (int row = 0; row < num_rows; ++row)
            for (int col = 0; col < num_cols; ++col)
                if (grid[row][col].oceans[OCEAN_PACIFIC] && grid[row][col].oceans[OCEAN_ATLANTIC])
                    pacific_and_atlantic.push_back(vector<int>{row, col});

        return pacific_and_atlantic;
    }
};

int main()
{
    // vector<vector<int>> heights
    // {
    //     {1,2,2,3,5},
    //     {3,2,3,4,4},
    //     {2,4,5,3,1},
    //     {6,7,1,4,5},
    //     {5,1,1,2,4}
    // };

    // vector<vector<int>> answer {{0,4},{1,3},{1,4},{2,2},{3,0},{3,1},{4,0}};

    // vector<vector<int>> heights
    // {
    //     {1,1},
    //     {1,1},
    //     {1,1}
    // };

    // vector<vector<int>> answer {{0,0},{0,1},{1,0},{1,1},{2,0},{2,1}};

    vector<vector<int>> heights
    {
        {1,2,3},
        {8,9,4},
        {7,6,5}
    };

    vector<vector<int>> answer {{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};

    Solution solution;
    vector<vector<int>> my_answer = solution.pacificAtlantic(heights);

    assert(my_answer.size() == answer.size());

    for (int i = 0; i < my_answer.size(); ++i)
    {
        assert(my_answer[i].size() == answer[i].size());

        for (int j = 0; j < my_answer[i].size(); ++j)
        {
            assert(my_answer[i][j] == answer[i][j]);
        }
    }

    cout << true << endl;
}