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
    int maxPathSum(TreeNode* root) {
        // In the general case, we can treep this like a graph problem
        // as any binary tree is a subset of a general tree whic his a
        // subset of a graph.
        //
        // Also, given that this problem asks us to find a maximum, we can
        // be fairly sure that the solution will involve some flavor of DP.

        // Because the data structrue in question is a tree and not a graph,
        // we know that we will be able to get from any one node to any other
        // node. Also, because we may only visit each node in the tree once
        // during our traversal, we know that there only exists one unique
        // path between any two distinct nodes. This already simplifies things
        // a bit because it means we should be able to traverse every path
        // within the tree in O(n^2). Hence, at minimum, we can come up
        // with a brute force solution.

        // Another thing to consider is that we may benefit by doing a 
    }
};