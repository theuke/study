/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // In order to perform a level order traversal,
        // we will have to take advantage of a queue.
        vector<vector<int>> levels;

        if (root)
        {
            queue<pair<int, TreeNode *>> node_queue;
            node_queue.push(pair<int, TreeNode *>(0, root));

            while(!node_queue.empty())
            {
                // Pop the node pair off of the stack.
                pair<int, TreeNode *> node_pair = node_queue.front();
                node_queue.pop();
                int level_index = get<0>(node_pair);
                TreeNode *node = get<1>(node_pair);

                // Place the node into its rightful spot in the ragged array.
                // If the vector of vectors is too small, increase the size by 1.
                // We are guaranteed to only need to increase by 1 since there
                // are no gaps in the depths.
                if (levels.size() == level_index)
                    levels.push_back(vector<int>());

                // Emplace at the back of the level vector the value of the node.
                levels[level_index].push_back(node->val);

                if (node->left)
                    node_queue.push(pair<int, TreeNode *>(level_index + 1, node->left));
                
                if (node->right)
                    node_queue.push(pair<int, TreeNode *>(level_index + 1, node->right));
            }
        }

        return levels;
    }
};