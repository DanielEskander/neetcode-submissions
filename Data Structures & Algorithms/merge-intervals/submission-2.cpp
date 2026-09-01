class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 0;
        for(int j = 1; j < intervals.size(); j++){
            if(intervals[i][1] >= intervals[j][0]){
                intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                intervals.erase(intervals.begin() + j);
            }
            else{
                i++;
            }
        }
        return intervals;
    }
};
