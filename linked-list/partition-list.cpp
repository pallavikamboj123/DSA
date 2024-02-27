/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* newHead = NULL;
        ListNode* tail = NULL;
        ListNode* temp = head;

        while(temp != NULL) {
            if(temp->val < x) {
                ListNode* newNode = new ListNode(temp->val);

                if(newHead == NULL) {
                    newHead = newNode;
                    tail = newNode;
                }
                else {
                    tail->next = newNode;
                    tail = tail->next;
                }
            }
            temp = temp->next;
        }

        temp = head;

        while(temp != NULL) {
            if(temp->val >= x) {
                ListNode* newNode = new ListNode(temp->val);

                if(newHead == NULL) {
                    newHead = newNode;
                    tail = newNode;
                }
                else {
                    tail->next = newNode;
                    tail = tail->next;
                }
            }
            temp = temp->next;
        }

        return newHead;
    }
};