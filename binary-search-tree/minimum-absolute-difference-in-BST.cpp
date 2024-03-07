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
    void inOrder(TreeNode* root, vector<int> &inorder) {
        if(root == NULL) return;

        inOrder(root->left, inorder);
        inorder.push_back(root->val);
        inOrder(root->right, inorder);
    }

    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        vector<int> inorder;

        inOrder(root, inorder);

        for(int i = 1; i < inorder.size(); i++) {
            ans = min(ans, inorder[i] - inorder[i-1]);
        }

        return ans;
    }
};