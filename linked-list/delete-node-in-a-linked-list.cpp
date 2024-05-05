#overwrite all subsequent nodes

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr = node;
        ListNode* next = node->next;

        while(next->next != NULL) {
            curr->val = next->val;
            curr = next;
            next = next->next;
        }

        curr->val = next->val;
        curr->next = NULL;
    }
};

#optimized solution

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr = node;
        ListNode* next = node->next;

        curr->val = next->val;
        curr->next = next->next;
    }
};

#remove unneccesary variables
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};