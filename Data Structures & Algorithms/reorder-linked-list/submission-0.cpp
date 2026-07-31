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
    ListNode* reverseList(ListNode* l){
        ListNode* curr = l;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* l1 = head;
        ListNode* l2;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        l2 = reverseList(slow->next);
        slow->next = nullptr;
        
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        while(curr1 && curr2){
            ListNode* tmp = curr1->next;
            ListNode* tmp2 = curr2->next;
            curr1->next = curr2;
            curr2->next = tmp;
            
            curr1 = tmp;
            curr2 = tmp2;
        }
    }
};
