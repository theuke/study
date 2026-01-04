#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>

using namespace std;

// class Solution {
// public:
//     int countComponents(int n, vector<vector<int>>& edges) {
//         // This problem really devloves into "how many distinct
//         // connected subgraphs are there in the graph?".
//         // So, one possible solution is to iterate over all of
//         // the nodes in the graph and perform a BFS / DFS on from
//         // each node, all the while keeping track of which nodes
//         // have and have not been visited. In parallel to this,
//         // it is neccesaary to keep track of how many times we
//         // have come across an unvisited node in the for loop.

//         // First, create an adjacency list.
//         vector<vector<int>> adjacency_list(n);

//         for (int i = 0; i < edges.size(); ++i)
//         {
//             adjacency_list[edges[i][0]].push_back(edges[i][1]);
//             adjacency_list[edges[i][1]].push_back(edges[i][0]);
//         }

//         int num_components = 0;
//         vector<bool> visited(n, false);

//         // Iterate over all of the nodes. It is expected most iteratrions will be skipped
//         // if there are not many connected components.
//         for (int i = 0; i < n; ++i)
//         {
//             if (!visited[i])
//             {
//                 ++num_components;

//                 // Perfrom BFS to visit all of the nodes connected to this node.
//                 queue<int> q;
//                 visited[i] = true;
//                 q.push(i);

//                 while(!q.empty())
//                 {
//                     int node = q.front();
//                     q.pop();

//                     for (int j = 0; j < adjacency_list[node].size(); ++j)
//                     {
//                         int neighbor = adjacency_list[node][j];

//                         if (!visited[neighbor])
//                         {
//                             visited[neighbor] = true;
//                             q.push(neighbor);
//                         }
//                     }
//                 }
//             }
//         }

//         return num_components;
//     }
// };

// class Solution {
// private:
//     int find(int node, vector<int>& parents)
//     {
//         // Find the node's root.
//         while (node != parents[node])
//             node = parents[node];
        
//         return node;
//     }

// public:
//     int countComponents(int n, vector<vector<int>>& edges) {
//         // The union find solution relies on the fact that we
//         // can have atmost n number of componenets (number of nodes).
//         // The idea is that when the addition of an edge results
//         // in two sets getting merged, then that means that the
//         // number of components decreases by 1.
//         int num_components = n;

//         vector<int> parents(n);

//         for (int i = 0; i < n; ++i)
//             parents[i] = i;
        
//         for (int i = 0; i < edges.size(); ++i)
//         {
//             int a_root = find(edges[i][0], parents);
//             int b_root = find(edges[i][1], parents);

//             if (a_root != b_root)
//             {
//                 parents[b_root] = a_root;
//                 -- num_components;
//             }
//         }

//         return num_components;
//     }
// };

class Solution {
private:
    int find(int node, vector<int>& parents)
    {
        // Find the node's root.
        while (node != parents[node])
            node = parents[node];
        
        return node;
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // The union find solution relies on the fact that we
        // can have atmost n number of componenets (number of nodes).
        // The idea is that when the addition of an edge results
        // in two sets getting merged, then that means that the
        // number of components decreases by 1.
        int num_components = n;

        vector<int> parents(n);

        for (int i = 0; i < n; ++i)
            parents[i] = i;
        
        for (int i = 0; i < edges.size(); ++i)
        {
            int a_root = find(edges[i][0], parents);
            int b_root = find(edges[i][1], parents);

            if (a_root != b_root)
            {
                parents[b_root] = a_root;
                -- num_components;
            }

            // This implementation does some extra rebalancing
            // to minimize the depth of each tree. Note that this is done
            // even when the two vertices of the edge belong to the same tree.
            // Optionally, we could choose to only perform the below procedure
            // when two distinct trees are actually unioned (i.e. not when the
            // edge is within nodes of the same tree.)
            int node = edges[i][0];
            while (node != a_root)
            {
                parents[node] = a_root;
                node = parents[node];
            }

            node = edges[i][1];
            while (node != a_root)
            {
                parents[node] = a_root;
                node = parents[node];
            }
        }

        return num_components;
    }
};

int main()
{
    int n = 5;
    vector<vector<int>> edges { {0, 1}, {1, 2}, {2, 4} };
    int answer = 2;

    Solution solution;
    int my_answer = solution.countComponents(n, edges);

    cout << "answer    = " << answer << endl;
    cout << "my_answer = " << my_answer << endl;
}