/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";

        if (root)
        {
            // Perform a level order traversal, making sure
            // to include null children in the queue.
            queue<TreeNode *> node_queue;
            node_queue.push(root);

            while (!node_queue.empty())
            {
                TreeNode *node = node_queue.front();
                node_queue.pop();

                // Add the node value to the string.
                if (node)
                {
                    str += to_string(node->val);

                    node_queue.push(node->left);
                    node_queue.push(node->right);
                }
                else
                {
                    str += "n";
                }

                // Delimit items via comma.
                str += ",";
            }
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root = NULL;

        if (!data.empty())
        {
            vector<TreeNode *> node_vec;
            const char *str = data.c_str();

            do
            {
                TreeNode *node;

                if (*str == 'n')
                {
                    node = NULL;
                }
                else
                {
                    node = new TreeNode;
                    node->val = stoi(str);
                }

                node_vec.push_back(node);

                while (*str != '\0' && *str != ',')
                    ++str;
                
                if (*str == ',')
                    ++str;

            } while (*str != '\0');

            int node_vec_size = node_vec.size();
            int next_index = 1;

            for (int i = 0; i < node_vec.size(); ++i)
            {
                if (node_vec[i])
                {
                    node_vec[i]->left = node_vec[next_index++];
                    node_vec[i]->right = node_vec[next_index++];
                }
            }

            root = node_vec[0];
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));