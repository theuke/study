#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

class Solution {
private:
    typedef struct Node
    {
        set<Node *>::iterator next;
        set<Node *> children;
    } Node;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // The task here is to construct a graph from the prerequisites
        // and then search for a cycle in the graph. Note that the graph
        // is a directed graph (goes from b to a) since one has to take
        // course b prior to taking course a.

        // We are essentially given a list of directed edges. Hence we need
        // to either a) construct a "real" ndoe based graph from the directed
        // adjacency list or b) traverse the graph using unly the directed
        // adjacency list. Note that the purpose of the graph traversal
        // is to detect whether or not there is a cycle in the graph. Note
        // that the graph may be disconnected, thus we may have to iterate
        // over multiple disconnected graphs.

        // Because there is no good / easy way to traverse the graph using
        // just the adjacency list, we will first construct a classic node
        // based graph and then traverse thar graph.

        int prerequisites_size = prerequisites.size();
        // Node *nodes = new Node[numCourses];
        Node *nodes = new Node[numCourses];
        set<Node *> unvisited;
        set<Node *> ancestors;

        // Set all of the nodes to initially be unvisited.
        for (int i = 0; i < numCourses; ++i)
            unvisited.insert(&nodes[i]);

        // Iterate through the adjacency list and make links from parent (prerequisite
        // course) to child (target course).
        for (int i = 0; i < prerequisites_size; ++i)
        {
            int target = prerequisites[i][0];
            int prerequisite = prerequisites[i][1];
            nodes[prerequisite].children.insert(&nodes[target]);
        }

        // Do a postorder depth first traversal of the graph.
        stack<Node *> st;

        while (!st.empty() || !unvisited.empty())
        {
            Node *node;

            if (!st.empty())
            {
                node = st.top();
                st.pop();
            }
            else
            {
                // Because we had to resort to pulling our next node from the
                // unvisited set, this means that the graph is a disconnected
                // graph and we are now beginning traversal of a new subgraph.
                // Hence, clear out the ancestors set.
                node = *unvisited.begin();
                node->next = node->children.begin();
            }

            bool process_this_node = true;

            for (; node->next != node->children.end() && process_this_node; ++node->next)
            {
                if (unvisited.count(*node->next))
                {
                    process_this_node = false;
                    break;
                }
            }

            // If all of the children of this node (if any)
            // have been explored, then visit the node itself as
            // it the highest indegree node in the current recursion stack.
            if (process_this_node)
            {
                // We have now visited the node!
                unvisited.erase(node);

                // Remove the node from the list of ancestors.
                ancestors.erase(node);
            }
            else
            {
                // Push the current node back on the stack and include it as an ancestor.
                ancestors.insert(node);
                st.push(node);

                Node *node_next = *(node->next);

                // If the next child of node is an ancestor, then that means we
                // have found a back-edge (i.e. cycle). Note because problem stated
                // no self loops are present, we could have checked this at the top
                // of the current scope, however, this current ordering is more robust
                // as it would catch self-loops.
                if (ancestors.count(node_next))
                    return false;

                // Push the next node onto the stack. Note it will thus get processed
                // before the current node (which we want because of postorder DFS).
                ancestors.insert(node_next);
                st.push(node_next);

                // Need to initialize the next node's next child iterator.
                node_next->next = node_next->children.begin();

                // Increment the next child to be checked for later on (this helps us
                // keep track of where we were when we go back down the recursion).
                ++(node->next);
            }
        }

        return true;
    }
};

int main()
{
    // int num_courses = 2;
    // vector<vector<int>> prerequisites { {1, 0} };

    // int num_courses = 2;
    // vector<vector<int>> prerequisites { {0, 1}, {1, 0} };

    // int num_courses = 5;
    // vector<vector<int>> prerequisites { {1,4},{2,4},{3,1},{3,2} };

    // int num_courses = 60;
    // vector<vector<int>> prerequisites
    // {
    //     {1,0},{2,0},{2,1},{3,1},{3,2},{4,2},{4,3},{5,3},{5,4},{6,4},{6,5},{7,5},{7,6},{8,6},{8,7},{9,7},{9,8},{10,8},{10,9},{11,9},{11,10},{12,10},{12,11},
    //     {13,11},{13,12},{14,12},{14,13},{15,13},{15,14},{16,14},{16,15},{17,15},{17,16},{18,16},{18,17},{19,17},{19,18},{20,18},{20,19},{21,19},{21,20},{22,20},
    //     {22,21},{23,21},{23,22},{24,22},{24,23},{25,23},{25,24},{26,24},{26,25},{27,25},{27,26},{28,26},{28,27},{29,27},{29,28},{30,28},{30,29},{31,29},{31,30}
    // };

    int num_courses = 100;
    vector<vector<int>> prerequisites
    {
        {1,0},{2,0},{2,1},{3,1},{3,2},{4,2},{4,3},{5,3},{5,4},{6,4},{6,5},{7,5},{7,6},{8,6},{8,7},{9,7},{9,8},{10,8},{10,9},{11,9},{11,10},{12,10},{12,11},
        {13,11},{13,12},{14,12},{14,13},{15,13},{15,14},{16,14},{16,15},{17,15},{17,16},{18,16},{18,17},{19,17},{19,18},{20,18},{20,19},{21,19},{21,20},{22,20},
        {22,21},{23,21},{23,22},{24,22},{24,23},{25,23},{25,24},{26,24},{26,25},{27,25},{27,26},{28,26},{28,27},{29,27},{29,28},{30,28},{30,29},{31,29},{31,30},
        {32,30},{32,31},{33,31},{33,32},{34,32},{34,33},{35,33},{35,34},{36,34},{36,35},{37,35},{37,36},{38,36},{38,37},{39,37},{39,38},{40,38},{40,39},{41,39},
        {41,40},{42,40},{42,41},{43,41},{43,42},{44,42},{44,43},{45,43},{45,44},{46,44},{46,45},{47,45},{47,46},{48,46},{48,47},{49,47},{49,48},{50,48},{50,49},
        {51,49},{51,50},{52,50},{52,51},{53,51},{53,52},{54,52},{54,53},{55,53},{55,54},{56,54},{56,55},{57,55},{57,56},{58,56},{58,57},{59,57},{59,58},{60,58},
        {60,59},{61,59},{61,60},{62,60},{62,61},{63,61},{63,62},{64,62},{64,63},{65,63},{65,64},{66,64},{66,65},{67,65},{67,66},{68,66},{68,67},{69,67},{69,68},
        {70,68},{70,69},{71,69},{71,70},{72,70},{72,71},{73,71},{73,72},{74,72},{74,73},{75,73},{75,74},{76,74},{76,75},{77,75},{77,76},{78,76},{78,77},{79,77},
        {79,78},{80,78},{80,79},{81,79},{81,80},{82,80},{82,81},{83,81},{83,82},{84,82},{84,83},{85,83},{85,84},{86,84},{86,85},{87,85},{87,86},{88,86},{88,87},
        {89,87},{89,88},{90,88},{90,89},{91,89},{91,90},{92,90},{92,91},{93,91},{93,92},{94,92},{94,93},{95,93},{95,94},{96,94},{96,95},{97,95},{97,96},{98,96},{98,97},{99,97}
    };


    Solution solution;
    bool can_finish = solution.canFinish(num_courses, prerequisites);

    cout << can_finish << endl;
}