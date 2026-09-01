class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {return a[0] < b[0];});
        int i = 0;
        int j = 1;
        while(j < intervals.size()){
            if(intervals[i][1] >= intervals[j][0]){
                intervals[i] = {intervals[i][0], intervals[j][1]};
                intervals.erase(intervals.begin() + j);
            }
            else{
                j++;
                i++;
            }
        }
        return intervals;
    }
};
