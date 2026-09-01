class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(auto& s : stones){
            maxHeap.push(s);
        }

        while(maxHeap.size() > 1){
            int v1 = maxHeap.top(); maxHeap.pop();
            int v2 = maxHeap.top(); maxHeap.pop();
            if(v1 == v2) continue;
            else maxHeap.push(v1 - v2);
        }
        return maxHeap.top();
    }
};
