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
    bool check(TreeNode* root, TreeNode* r) {
        if(root == NULL && r == NULL) return true;
        if(root == NULL || r == NULL) return false;

        if(root->val != r->val) return false;

        bool left = check(root->left, r->right);
        bool right = check(root->right, r->left);

        if(!left) return false;
        if(!right) return false;

        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};