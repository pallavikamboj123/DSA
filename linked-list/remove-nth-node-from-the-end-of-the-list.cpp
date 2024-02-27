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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;

        while(temp != NULL) {
            count++;
            temp = temp->next;
        }

        int nodeNumber = count - n + 1;

        if(nodeNumber == 1) return head->next;

        ListNode* pre = NULL;
        ListNode* next = NULL;
        temp = head;

        count = 1;
        while(temp != NULL) {
            if(count == nodeNumber) {
                pre->next = temp->next;
                break;
            }
            else {
                pre = temp;
            }
            temp = temp->next;
            count++;
        }

        return head;
    }
};