/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](Interval a, Interval b){ return a.start < b.start; });
        
        int i = 0;
        int j = 1;
        while(j < intervals.size()){
            if(intervals[i].end > intervals[j].start)
                return false;
            i++;
            j++;
        }
        return true;
    }
};
