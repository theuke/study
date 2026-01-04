#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>

using namespace std;

// // This solution is naive and only relies on us checking whether
// // the given graph has no cycles and is connected (as those are teh
// // characteristics that define a tree). Note that in order to detect
// // a cycle in an undirected graph, we need to check if the currently
// // visited node has any neighbors that have already been visited
// // but 
// class Solution {
// public:
//     bool validTree(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> adjacency_list(n);

//         // Iterate through all of the edges and fill out the adjacency list.
//         for (int i = 0; i < edges.size(); ++i)
//         {
//             adjacency_list[edges[i][0]].push_back(edges[i][1]);
//             adjacency_list[edges[i][1]].push_back(edges[i][0]);
//         }

//         map<int, int> seen_parent;
//         queue<int> q;
//         seen_parent[0] = -1;
//         q.push(0);

//         while(!q.empty())
//         {
//             int node = q.front();
//             q.pop();

//             for (int i = 0; i < adjacency_list[node].size(); ++i)
//             {
//                 int neighbor = adjacency_list[node][i];

//                 // If the current node's parent is the neighbor in question
//                 // then that implies that the neightbor has already been seen. However
//                 // we do not count this as a cycle because it is  a "trivial" cycle
//                 // (i.e. a cycle defined by a single undirected edge). Else if the neightbor
//                 // is not he current node's parent, but yet it has already been seen, then
//                 // that means we have found a cycle.
//                 if (seen_parent[node] == neighbor)
//                 {
//                     continue;
//                 }
//                 else if (seen_parent.count(neighbor))
//                 {
//                     return false; 
//                 }
//                 else
//                 {
//                     seen_parent[neighbor] = node;
//                     q.push(neighbor);
//                 }
//             }
//         }

//         // Note this last check here is to catch the case that the graph has no cycle
//         // but is disconnected,
//         return seen_parent.size() == n;
//     }
// };

// This solution relies on us knowing that a graph is a tree only if
// a) It has number of edges equal to number of nodes - 1.
// b) The grph is connected (i.e. we can visit all nodes from
//    all other nodes).
//
// So, if we can't visit all nodes while doing a DFS or BFS when
// the number of edges is equal to number of nodes -1, that means
// that there is a cycle in the graph AND the graph is disconnected
// at into precisley two connected graphs: One with a cycle and the
// other with no cycle (This last part is my own speculation).
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false;

        vector<vector<int>> adjacency_list(n);

        // Iterate through all of the edges and fill out the adjacency list.
        for (int i = 0; i < edges.size(); ++i)
        {
            adjacency_list[edges[i][0]].push_back(edges[i][1]);
            adjacency_list[edges[i][1]].push_back(edges[i][0]);
        }

        set<int> seen;
        queue<int> q;
        seen.insert(0);
        q.push(0);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int i = 0; i < adjacency_list[node].size(); ++i)
            {
                int neighbor = adjacency_list[node][i];

                // Note that by checking whether the neighbor is seen
                // here (and intializing the first node as seen) we gaurantee
                // that the queue will never contain any duplicate items which
                // saves us some time since we don't have to push / pop the
                // item onto the queue needlessly.
                if (!seen.count(neighbor))
                {
                    seen.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        return seen.size() == n;
    }
};

int main()
{
    // int n = 5;
    // vector<vector<int>> edges { {0, 1}, {0, 2}, {0, 3}, {1, 4} };
    // bool answer = true;

    int n = 1;
    vector<vector<int>> edges { };
    bool answer = true;

    Solution solution;
    bool my_answer = solution.validTree(n, edges);

    cout << "answer    = " << answer << endl;
    cout << "my_answer = " << my_answer << endl;
}