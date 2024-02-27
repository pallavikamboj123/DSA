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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        int count = 1;
        ListNode* start = NULL;
        stack<int> st;

        while(temp != NULL) {
            if(count == left) {
                start = temp;
            }

            if(count >= left && count <= right) {
                st.push(temp->val);
            }

            if(count == right) {
                while(st.size()) {
                    start->val = st.top();
                    st.pop();
                    start = start->next;
                }
                break;
            }

            temp = temp->next;
            count++;
        }

        return head;
    }
};