/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newHead = NULL;
        Node* tail = NULL;
        Node* temp = head;

        unordered_map<Node*, Node*> m;

        while(head != NULL) {
            Node* newNode = new Node(head->val);

            if(newHead == NULL) {
                newHead = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = tail->next;
            }

            m[head] = newNode;

            head = head->next;
        }

        Node* curr = newHead;
        while(temp != NULL) {
            if(temp->random == NULL) curr->random = NULL;
            else curr->random = m[temp->random];

            temp = temp->next;
            curr = curr->next;
        }

        return newHead;

    }
};