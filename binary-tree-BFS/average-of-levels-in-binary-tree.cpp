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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;

        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            double sum = 0;
            double count = 0;

            int size = q.size();

            while(size > 0) {
                TreeNode* i = q.front();
                q.pop();
                sum += i->val;
                count++;
                if(i->left != NULL) q.push(i->left);
                if(i->right != NULL) q.push(i->right);

                size--;
            }

            ans.push_back(sum/count);
        }

        return ans;

    }
};