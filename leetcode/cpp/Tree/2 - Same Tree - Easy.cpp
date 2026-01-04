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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Catch the case of both trees being empty
        // or one being empty and the other non-empty
        // or the roots not matching up of the bat.
        if (!p && !q)
            return true;
        else if (!p || !q || p->val != q->val)
            return false;

        // For the trees to be the same both the structure and
        // values must be identical.

        // Recursive solution.
        // return worker(p, q);


        // Iterative solution
        stack<pair<TreeNode *, TreeNode *>> node_stack;
        node_stack.push(pair<TreeNode *, TreeNode *>(p, q));

        while (!node_stack.empty())
        {
            pair<TreeNode *, TreeNode *> node_pair = node_stack.top();
            TreeNode *p_node = get<0>(node_pair);
            TreeNode *q_node = get<1>(node_pair);
            node_stack.pop();

            bool check_left;
            bool check_right;

            if (!p_node->left && p_node->left == q_node->left)
            {
                // Both left children are NULL.
                check_left = false;
            }
            else if (p_node->left && q_node->left && p_node->left->val == q_node->left->val)
            {
                // Both left children are not NULL and their values are equivalent.
                check_left = true;
            }
            else
            {
                // The two left children are different.
                return false;
            }

            if (!p_node->right && p_node->right == q_node->right)
            {
                // Both right children are NULL.
                check_right = false;
            }
            else if (p_node->right && q_node->right && p_node->right->val == q_node->right->val)
            {
                // Both right children are not NULL and their values are equivalent.
                check_right = true;
            }
            else
            {
                // The two right children are different.
                return false;
            }

            if (check_left)
                node_stack.push(pair<TreeNode *, TreeNode *>(p_node->left, q_node->left));

            if (check_right)
                node_stack.push(pair<TreeNode *, TreeNode *>(p_node->right, q_node->right));
        }

        return true;
    }

private:
    bool worker(TreeNode* p, TreeNode* q)
    {
        bool check_left;
        bool check_right;

        if (!p->left && p->left == q->left)
        {
            // Both left children are NULL.
            check_left = false;
        }
        else if (p->left && q->left && p->left->val == q->left->val)
        {
            // Both left children are not NULL and their values are equivalent.
            check_left = true;
        }
        else
        {
            // The two left children are different.
            return false;
        }

        if (!p->right && p->right == q->right)
        {
            // Both right children are NULL.
            check_right = false;
        }
        else if (p->right && q->right && p->right->val == q->right->val)
        {
            // Both right children are not NULL and their values are equivalent.
            check_right = true;
        }
        else
        {
            // The two right children are different.
            return false;
        }
        
        if ((!check_left || worker(p->left, q->left)) && (!check_right || worker(p->right, q->right)))
            return true;
        
        return false;
    }
};