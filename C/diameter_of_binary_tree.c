/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int compute(struct TreeNode* root, int* diameter){
    if(!root) return 0;
    int right_depth = compute(root->right, diameter);
    int left_depth = compute(root->left, diameter);
    int length = right_depth + left_depth;
    if(length > *diameter) *diameter = length;
    return fmax(right_depth, left_depth) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    int diameter = 0;
    compute(root, &diameter);
    return diameter;
}
