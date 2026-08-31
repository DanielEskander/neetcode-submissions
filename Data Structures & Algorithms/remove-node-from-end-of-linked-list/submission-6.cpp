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
        int size = 0;
        ListNode* cur = head;
        while(cur){
            cur = cur->next;
            size++;
        }

        int idx = 0;
        cur = head;
        ListNode* prev = nullptr;
        while(cur){
            if(size - idx == n){
                if(prev == nullptr){
                    ListNode* tmp = head->next;
                    head->next = nullptr;
                    delete(head);
                    return tmp;
                }
                else{
                    prev->next = cur->next;
                    cur->next = nullptr;
                    delete(cur);
                    return head;
                }
            }
            else{
                idx++;
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
