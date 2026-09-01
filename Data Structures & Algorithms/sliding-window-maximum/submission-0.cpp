class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> tracker;
        vector<int> res;
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(tracker.size() == 0 || nums[j] >= tracker.back().first){
                tracker.push_back({nums[j], j});
            }

            if(j - i + 1 == k){
                res.push_back(tracker.back().first);
                while(tracker.size() > 0 && tracker.front().second < j - i - 1){
                    tracker.pop_front();
                }
                i++;
            }
        }
        return res;
    }
};
