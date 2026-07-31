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
    bool hasCycle(ListNode* head) {
        ListNode* rab = head;
        ListNode* tur = head;
        while(rab && rab->next){
            rab = rab->next->next;
            tur = tur->next;
            
            if(rab == tur) return true;
        }
        return false;
    }
};
