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
        ListNode* it = head;
        while(it){
            size++;
            it = it->next;
        }

        int idx = 0;
        it = head;
        ListNode* prev = nullptr;
        while(it){
            idx++;
            if(n == size - idx + 1){
                if(!prev){
                    ListNode* newNode = nullptr;
                    delete head;
                    return newNode;
                }
                else{
                    prev->next = it->next;
                    it->next = nullptr;
                    delete it;
                    return head;
                }
            }
            prev = it;
            it = it->next;
        }
    }
};
