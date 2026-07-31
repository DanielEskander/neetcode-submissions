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
        ListNode* curr = head;
        while(curr){
            size++;
            curr = curr->next;
        }

        int index = 0;
        ListNode* prev = nullptr;
        curr = head;
        while(curr){
            if(size - index == n){
                if(!prev){
                    ListNode* tmp = head->next;
                    head->next = nullptr;
                    delete head;
                    head = tmp;
                }
                else{
                    prev->next = curr->next;
                    curr->next = nullptr;
                    delete curr;
                }
                break;
            }
            prev = curr;
            curr = curr->next;
            index++;
        }
        return head;
    }
};
