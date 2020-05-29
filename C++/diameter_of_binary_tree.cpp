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
    int diameter = 0;
    
    int compute(TreeNode* root) {
        if(!root) return 0;
        int right_depth = compute(root->right);
        int left_depth = compute(root->left);
        int length = right_depth + left_depth;
        if(length > diameter) diameter = length;
        return max(right_depth, left_depth) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        compute(root);
        return diameter;
    }
};
