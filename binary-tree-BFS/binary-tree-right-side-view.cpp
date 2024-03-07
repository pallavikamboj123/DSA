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

    void helper(TreeNode* root, int height, map<int, int> &mmap) {
        if(root == NULL) return;

        mmap[height] = root->val;

        helper(root->left, height + 1, mmap);
        helper(root->right, height + 1, mmap);

        return;
    }

    vector<int> rightSideView(TreeNode* root) {
        map<int, int> mmap;
        vector<int> ans;

        helper(root, 0, mmap);

        map<int, int>::iterator itr;

        for(itr = mmap.begin(); itr !=mmap.end(); itr++) {
            ans.push_back(itr->second);
        }

        return ans;
    }
};