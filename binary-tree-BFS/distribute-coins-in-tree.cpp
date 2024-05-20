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
    int moves = 0;
    int coins(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) {
            return root->val - 1;
        }

        int left = coins(root->left);
        int right = coins(root->right);

        moves += abs(left) + abs(right);

        return left + right + root->val - 1;
    }
    int distributeCoins(TreeNode* root) {
        coins(root);
        return moves;

    }
};