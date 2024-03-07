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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        int ans_size = 1;

        while(!q.empty()) {
            int size = q.size();

            vector<int> v;

            while(size > 0) {
                TreeNode* front = q.front();
                q.pop();

                v.push_back(front->val);

                if(front->left != NULL) q.push(front->left);
                if(front->right != NULL) q.push(front->right);

                size--;
            }

            if(ans_size %2 == 0) reverse(v.begin(), v.end());

            ans_size++;
            ans.push_back(v);
        }

        return ans;
    }
};