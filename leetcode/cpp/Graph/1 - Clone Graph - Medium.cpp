/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;

        // This task's solution neccessitates that we somehow keep track of
        // which nodes have already visited (so that we do not make any extra copies
        // of the nodes). Second then is what should the traversal type be? DFS or BFS?

        #define MAX_NODES   101
        Node *clones = new Node[MAX_NODES];
        for (int i = 1; i < MAX_NODES; ++i)
            clones[i].val = 0;

        // Make a local copy of the root node.
        clones[node->val].val = node->val;

        // Perfrom a BFS of the source graph.
        queue<Node*> q;
        q.push(node);

        while (!q.empty())
        {
            // Pop the node off to visit it.
            Node *n = q.front();
            q.pop();

            int n_val = n->val;
            int num_neighbors = n->neighbors.size();

            // To ensure BFS traversal, simply enqueue all of the node's
            // unvisited neighbors.
            for (int i = 0; i < num_neighbors; ++i)
            {
                int neighbor_val = n->neighbors[i]->val;

                if (clones[neighbor_val].val == 0)
                {
                    // The neightbor is unvisited. This also implies that no local copy
                    // of the neighbor node exists. Thus make a local copy of the neighboring node
                    // and put the source copy of the same node on the queue so that it is visisted later on. 
                    clones[neighbor_val].val = neighbor_val;
                    q.push(n->neighbors[i]);
                }
                
                // At this point we now alrady have a local copy of the neighboring node,
                // hence add it to the currently visited node's list of neighbors.
                clones[n_val].neighbors.emplace_back(&clones[neighbor_val]);
            }
        }

        return &clones[node->val];
    }
};