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
    void addNode(TreeNode* root, int val, int depth, int currDept) {
        if(currDept == depth - 1) {

            TreeNode* left = root->left;
            TreeNode* right = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = left;
            root->right->right = right;

            return;
        }

        if(root->left != NULL) addNode(root->left, val, depth, currDept + 1);

        if(root->right != NULL) addNode(root->right, val, depth, currDept + 1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;

            return newNode;
        }

        addNode(root, val, depth, 1);

        return root;
    }
};