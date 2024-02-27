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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> m;

        ListNode* temp = head;

        while(temp != NULL) {
            if(m.find(temp->val) == m.end()) {
                m[temp->val] = 1;
            }
            else {
                m[temp->val] = m[temp->val] + 1;
            }

            temp = temp->next;
        }

        temp = head;

        map<int, int>::iterator itr;

        ListNode* pre = NULL;

        for(itr = m.begin(); itr != m.end(); itr++) {
            if(itr->second != 1) continue;

            temp->val = itr->first;
            pre = temp;
            temp = temp->next;
        }

        if(pre!= NULL) {
            pre->next = NULL;
            return head;
        }

        return NULL;
    }
};