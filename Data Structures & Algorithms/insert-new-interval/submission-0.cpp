class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        int i = 0;
        int j = 1;
        while(j < intervals.size()){
            if(intervals[i][1] >= intervals[j][0]){
                intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                intervals.erase(intervals.begin() + j);
            }
            else{
                i++;
                j++;
            }
        }
        return intervals;
    }
};
