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
        if(lists.empty()) return nullptr;

        auto cmp = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        for(ListNode* l : lists){
            if(l){
                minHeap.push(l);
            }
        }

        ListNode* res = new ListNode(0);
        ListNode* dummy = res;
        while(!minHeap.empty()){
            ListNode* tmp = minHeap.top();
            minHeap.pop();
            dummy->next = tmp;
            dummy = dummy->next;
            
            if(tmp->next){
                minHeap.push(tmp->next);
            }
        }
        return res->next;
    }
};
