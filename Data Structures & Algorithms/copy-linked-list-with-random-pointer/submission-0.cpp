/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> tracker;
        tracker[nullptr] = nullptr;
        Node* curr = head;
        while(curr != nullptr){
            if(tracker.find(curr) == tracker.end()){
                tracker[curr] = new Node(0);
            }
            tracker[curr]->val = curr->val;
            if(tracker.find(curr->next) == tracker.end()){
                tracker[curr->next] = new Node(0);
            }
            tracker[curr]->next = tracker[curr->next];
            if(tracker.find(curr->random) == tracker.end()){
                tracker[curr->random] = new Node(0);
            }
            tracker[curr]->random = tracker[curr->random];
            curr = curr->next;
        }
        return tracker[head];
    }
};
