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
        if(!node) return node;

        unordered_map<Node*, Node*> oldToNew;
        oldToNew[nullptr] = nullptr;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* n = q.front();
            q.pop();

            if(!oldToNew.contains(n)){
                oldToNew[n] = new Node(n->val);
            }

            for(auto& nei : n->neighbors){
                if(!oldToNew.contains(nei)){
                    q.push(nei);
                    oldToNew[nei] = new Node(nei->val);
                }
                oldToNew[n]->neighbors.push_back(oldToNew[nei]);
            }
        }
        return oldToNew[node];
    }
};
