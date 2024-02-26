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
    ListNode* rev(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;

        while(curr != NULL) {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }

        return pre;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int carry = 0;
        while(l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val + carry;
            carry = sum >= 10 ? 1 : 0;

            ListNode* newNode = new ListNode(sum%10);

            if(head == NULL) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = tail->next;
            }

            l1 = l1->next;
            l2 = l2->next;

        }

        while(l1 != NULL) {
            int sum = l1->val + carry;

            carry = sum >= 10 ? 1 : 0;

            ListNode* newNode = new ListNode(sum%10);

            if(head == NULL) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = tail->next;
            }

            l1 = l1->next;
        }

        while(l2 != NULL) {
            int sum = l2->val + carry;

            carry = sum >= 10 ? 1 : 0;

            ListNode* newNode = new ListNode(sum%10);

            if(head == NULL) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = tail->next;
            }

            l2 = l2->next;
        }

        if(carry) {
            ListNode* newNode = new ListNode(1);
            tail->next = newNode;
            tail = tail->next;
        }

        return head;

    }
};