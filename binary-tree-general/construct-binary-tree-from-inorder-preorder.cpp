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
    TreeNode* func(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie, unordered_map<int, int> &mmap) {
        if(ps > pe || is > ie) return NULL;

        TreeNode* root = new TreeNode(preorder[ps]);

        int index = mmap[root->val];

        int mid = index - is;

        root->left = func(preorder, ps + 1, ps + mid, inorder, is, index - 1, mmap);

        root->right = func(preorder, ps + mid + 1, pe,
        inorder, index + 1, ie, mmap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mmap;

        for(int i = 0; i < inorder.size(); i++) {
            mmap[inorder[i]] = i;
        }

        return func(preorder, 0, preorder.size() - 1, inorder, 0 , inorder.size() - 1, mmap);
    }
};