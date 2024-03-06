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
    int totalSum = 0;
    void helper(TreeNode* root, string sum, int multiple) {
        sum += to_string(root->val);

        if(root->left == NULL && root->right == NULL) {
            int a = stoi(sum);
            totalSum += a;
            return;
        }

        if(root->left != NULL) helper(root->left, sum, multiple + 1);
        if(root->right != NULL) helper(root->right, sum, multiple + 1);

        return;

    }
    int sumNumbers(TreeNode* root) {
        helper(root, "", 0);

        return totalSum;
    }
};