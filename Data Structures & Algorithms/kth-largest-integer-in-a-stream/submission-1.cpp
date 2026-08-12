class KthLargest {
public:
    priority_queue<int> maxHeap;
    int kv;
    KthLargest(int k, vector<int>& nums) {
        this->kv = k;
        for(auto& n : nums){
            maxHeap.push(n);
        }
    }
    
    int add(int val) {
        maxHeap.push(val);
        priority_queue<int> tmpHeap = maxHeap;
        int count = 1;
        while(!tmpHeap.empty() && count < kv){
            tmpHeap.pop();
            count++;
        }
        return count == kv ? tmpHeap.top() : -1;
    }
};
