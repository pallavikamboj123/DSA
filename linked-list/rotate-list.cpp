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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;

        ListNode* temp = head;

        int count = 0;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }


        ListNode* pre = NULL;
        ListNode* curr = head;
        ListNode* start = NULL;

        int n = count - (k%count);

        if(n == count) return head;

        count = 1;
        while(curr != NULL) {
            if(count == n + 1) {
                start = curr;
                pre->next = NULL;
            }
            pre = curr;
            curr = curr->next;
            count++;
        }

        if(pre != NULL) pre->next = head;

        return start;
     }
};