# O(n) space and time using stack
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<int> s;

        ListNode* temp = head;

        while(temp != NULL) {
            while(!s.empty() && s.top() < temp->val) {
                s.pop();
            }

            s.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        ListNode* pre = NULL;

        while(!s.empty()) {
            temp->val = s.top();
            s.pop();
            pre = temp;
            temp = temp->next;
        }

        pre->next = NULL;

        pre = NULL;
        temp = head;
        ListNode* next = temp->next;

        while(temp->next != NULL) {
            temp->next = pre;
            pre = temp;
            temp = next;
            next = temp->next;
        }

        temp->next = pre;
        pre = temp;


        return pre;
    }
};