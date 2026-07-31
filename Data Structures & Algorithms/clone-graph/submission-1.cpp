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
        if(!node) return nullptr;
        unordered_map<Node*, Node*> oldToNew;
        queue<Node*> q;

        oldToNew[node] = new Node(node->val);
        q.push(node);

        while(!q.empty()){
            Node* tmp = q.front(); q.pop();
            for(auto& n : tmp->neighbors){
                if(!oldToNew.contains(n)){
                    q.push(n);
                    oldToNew[n] = new Node(n->val);
                }
                oldToNew[tmp]->neighbors.push_back(oldToNew[n]);
            }
        }

        // q.push(node);
        // while(!q.empty()){
        //     Node* tmp = q.front(); q.pop();
        //     oldToNew[tmp]->neig = new Node(tmp->val);
        //     for(auto& n : tmp->neighbors){
        //         q.push(n);
        //     }
        // }

        return oldToNew[node];
    }
};
