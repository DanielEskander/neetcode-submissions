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
        int idx = 0;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        
        while(curr){
            size++;
            curr = curr->next;
        }

        curr = head;
        while(curr){
            if(n == size - idx){
                if(!prev){
                    ListNode* newNode = head->next;
                    delete head;
                    return newNode;
                }
                prev->next = curr->next;
                curr->next = nullptr;
                delete curr;
                return head;
            }
            prev = curr;
            curr = curr->next;
            idx++;
        }
        return head;
    }
};
