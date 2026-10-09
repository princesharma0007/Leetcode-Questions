/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {


if(root == NULL) return false;
if(root->left == NULL && root->right == NULL){
    return targetSum == root->val;
}
int remain= targetSum-root->val;

bool left = hasPathSum(root->left,remain);
bool right = hasPathSum(root->right,remain);
return left || right;
}