class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxQ;
        for(auto& n : nums){
            maxQ.push(n);
        }

        for(int i = k - 1; i > 0; i--){
            maxQ.pop();
        }
        return maxQ.top();
    }
};
