/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;

        queue<Node*> q;

        Node* arr[101];
        bool visited[101];

        for(int i = 0; i < 101; i++) {
            visited[i] = false;
            arr[i] = NULL;
        }

        q.push(node);
        visited[1] = true;

        while(!q.empty()) {
            Node* top = q.front();
            q.pop();

            if(arr[top->val] == NULL) {
                Node* temp = new Node(top->val);
                arr[top->val] = temp;
            }

            for(int i = 0; i < top->neighbors.size(); i++) {
                Node* n = top->neighbors[i];
                if(!visited[n->val]) {
                    q.push(n);
                    visited[n->val] = true;

                    Node* temp = new Node(n->val);

                    arr[n->val] = temp;

                    Node* newNode = arr[top->val];
                    newNode->neighbors.push_back(temp);
                }
                else {
                    Node* newNode = arr[top->val];
                    newNode->neighbors.push_back(arr[n->val]);
                }
            }
        }

        return arr[1];
    }
};