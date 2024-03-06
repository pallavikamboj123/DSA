/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void helper(Node* root, unordered_map<int, vector<Node*>> &mmap, int height) {
        if(root == NULL) return;

        if(mmap.find(height) == mmap.end()) {
            vector<Node*> v;
            v.push_back(root);
            mmap[height] = v;
        }
        else {
            mmap[height].push_back(root);
        }

        helper(root->left, mmap, height + 1);

        helper(root->right, mmap, height + 1);

        return;
    }

    Node* connect(Node* root) {
        if(root == NULL) return NULL;

        unordered_map<int, vector<Node*>> mmap;

        helper(root, mmap, 0);

        unordered_map<int, vector<Node*>>::iterator itr;

        for(itr = mmap.begin(); itr != mmap.end(); itr++) {
            vector<Node*> v = itr->second;

            for(int i = 1; i < v.size(); i++) {
                v[i-1]->next = v[i];
            }

            v[v.size()-1]->next = NULL;
        }

        return root;
    }
};