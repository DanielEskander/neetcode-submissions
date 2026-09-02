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
    ListNode* getKth(ListNode* head, int k){
        ListNode* cur = head;
        while(cur && k > 0){
            cur = cur->next;
            k--;
        }
        return cur;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* res = new ListNode(0);
        ListNode* groupPrev = res;
        groupPrev->next = head;
        while(true){
            ListNode* kth = getKth(groupPrev, k);
            if(!kth) break;

            ListNode* groupNext = kth->next;
            ListNode* groupStart = groupPrev->next;
            ListNode* cur = groupStart;
            ListNode* prev = groupPrev;
            while(cur != groupNext){
                ListNode* tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
            }

            groupStart->next = groupNext;
            groupPrev->next = prev;
            groupPrev = groupStart;
        }
        return res->next;
    }
};
