class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> tracker;
        vector<int> res;
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            while(!tracker.empty() && tracker.back().first < nums[j]){
                tracker.pop_back();
            }
            tracker.push_back({nums[j], j});

            while(tracker.size() > 0 && tracker.front().second < i){
                tracker.pop_front();
            }

            if(j - i + 1 == k){
                res.push_back(tracker.front().first);
                i++;
            }
        }
        return res;
    }
};
