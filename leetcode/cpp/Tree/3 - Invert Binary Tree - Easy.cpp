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
    TreeNode* invertTree(TreeNode* root) {
        // Just need to swap the left and right nodes.

        // // Recursive solution.
        // if (root)
        //     worker(root);
        

        // Iterative solution.
        if (root)
        {
            stack<TreeNode *> node_stack;
            node_stack.push(root);

            while (!node_stack.empty())
            {
                TreeNode *node = node_stack.top();
                node_stack.pop();

                TreeNode *temp = node->left;
                node->left = node->right;
                node->right = temp;

                if (node->left)
                    node_stack.push(node->left);
                
                if (node->right)
                    node_stack.push(node->right);
            }
        }

        return root;
    }

    void worker(TreeNode *root)
    {
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        if (root->left)
            worker(root->left);
        
        if (root->right)
            worker(root->right);
    }
};