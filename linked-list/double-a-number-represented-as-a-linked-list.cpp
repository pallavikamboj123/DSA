#by reversing a linked list O(n) time and O(1) space
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* next = head->next;

        while(head != NULL) {
            head->next = pre;
            pre = head;
            head = next;
            if(next != NULL)
                next = next->next;
        }

        return pre;
    }
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);

        int carry = 0;

        ListNode* temp = head;
        ListNode* pre = NULL;

        while(temp != NULL) {
            int v = temp->val * 2 + carry;
            carry = v >= 10 ? 1 : 0;

            v = v >= 10 ? v - 10 : v;

            temp->val = v;
            pre = temp;

            temp = temp->next;
        }

        if(carry) {
            ListNode* newNode = new ListNode(carry);
            pre->next = newNode;
        }

        return reverse(head);
    }
};

#using recursion

class Solution {
public:
    int helper(ListNode* head) {
        if(head == NULL) return 0;

        int val = head->val * 2 + helper(head->next);

        head->val = val % 10;

        return val / 10;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry = helper(head);

        if(carry) {
            head = new ListNode(carry, head);
        }

        return head;
    }
};