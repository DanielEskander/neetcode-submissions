class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> tracker;
        int i = 0;
        int j = 0;
        while(j < nums.size()){
            while(!tracker.empty() && tracker.top().second < i){
                tracker.pop();
            }
            tracker.push({nums[j], j});
            if(j >= k - 1){
                res.push_back(tracker.top().first);
                i++;
            }
            j++;
        }
        return res;
    }
};
