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
    ListNode* getKth(ListNode* cur, int k){
        while(cur && k > 0){
            cur = cur->next;
            k--;
        }
        return cur;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* res = new ListNode(0, head);
        ListNode* groupPrev = res;

        while(true){
            ListNode* kth = getKth(groupPrev, k);
            if(!kth) break;

            ListNode* groupNext = kth->next;
            ListNode* cur = groupPrev->next;
            ListNode* prev = groupNext;
            while(cur != groupNext){
                ListNode* tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
            }

            ListNode* tmp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = tmp;
        }
        return res->next;
    }
};
