/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> oldToNew;
        oldToNew[nullptr] = nullptr;
        
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* tmp = q.front(); q.pop();
            oldToNew[tmp] = new Node(tmp->val);
            vector<Node*> neighbors;
            for(auto& n : tmp->neighbors){
                oldToNew[n] = new Node(n->val);
                q.push(n);
            }
            oldToNew[tmp]->neighbors = 
        }

        q.push(node);
        while(!q.empty()){
            Node* tmp = q.front(); q.pop();
            oldToNew[tmp]->neig = new Node(tmp->val);
            for(auto& n : tmp->neighbors){
                q.push(n);
            }
        }

        return oldToNew[node];
    }
};
