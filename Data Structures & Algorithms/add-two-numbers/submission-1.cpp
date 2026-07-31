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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* op1 = l1;
        ListNode* op2 = l2;
        ListNode res(0);
        ListNode* dummy = &res;
        while(op1 || op2 || carry > 0){
            int sum = 0;
            if(op1){
                sum += op1->val;
                op1 = op1->next;
            }
            if(op2){
                sum += op2->val;
                op2 = op2->next;
            }
            sum += carry;
            carry = sum / 10;
            sum %= 10;
            dummy->next = new ListNode(sum);
            dummy = dummy->next;
        }
        return res.next;
    }
};
