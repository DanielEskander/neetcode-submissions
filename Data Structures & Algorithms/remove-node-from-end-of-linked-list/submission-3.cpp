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
            if(n == size - idx){
                if(!prev){
                    ListNode* newNode = head->next;
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
            idx++;
        }
        return head;
    }
};
