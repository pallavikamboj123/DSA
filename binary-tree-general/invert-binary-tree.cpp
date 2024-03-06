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
    TreeNode* func(TreeNode* root, TreeNode* ans) {
        if(root == NULL) return ans;

        TreeNode* temp = new TreeNode(root->val);
        ans = temp;

        TreeNode* left = func(root->right, ans->left);
        TreeNode* right = func(root->left, ans->right);

        ans->left = left;
        ans->right = right;

        return ans;
    }

    TreeNode* invertTree(TreeNode* root) {
        return func(root, NULL);
    }
};