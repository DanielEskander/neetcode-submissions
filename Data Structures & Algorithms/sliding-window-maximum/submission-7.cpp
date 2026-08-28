class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> q;
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            while(!q.empty() && q.top().second < i) q.pop();
            
            q.push({nums[j], j});
            if(j >= k - 1){
                res.push_back(q.top().first);
                i++;
            }
        }
        return res;
    }
};
