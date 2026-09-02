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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        ListNode* res = new ListNode();
        ListNode* dummy = res;
        for(ListNode* l : lists){
            if(!l) continue;
            
            q.push(l);
        }
        while(!q.empty()){
            dummy->next = q.top();
            ListNode* nxt = q.top()->next;
            q.pop();

            if(nxt) q.push(nxt);
            dummy = dummy->next;
        }
        return res->next;
    }
};
