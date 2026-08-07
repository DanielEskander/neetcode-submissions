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
        auto comp = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> minHeap(comp);
        ListNode* res = new ListNode(0);
        ListNode* dummy = res;
        for(auto l : lists){
            if(l) minHeap.push(l);
        }

        while(!minHeap.empty()){
            ListNode* tmp = minHeap.top();
            minHeap.pop();
            if(tmp->next) minHeap.push(tmp->next);

            dummy->next = tmp;
            dummy = dummy->next;
        }
        return res->next;
    }
};
