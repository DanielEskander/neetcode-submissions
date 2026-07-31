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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
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
        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* tmp = reverseList(slow->next);
        slow->next = nullptr;

        ListNode* l1 = head;
        ListNode* l2 = tmp;

        while(l2){
            ListNode* tmp = l1->next;
            ListNode* tmp2 = l2->next;
            l1->next = l2;
            l2->next = tmp;

            l2 = tmp2;
            l1 = tmp;
        }
    }
};
