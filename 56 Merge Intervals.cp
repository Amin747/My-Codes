class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        int cur = 0;
        int index =0;
        int size = intervals.size()-1;
        sort(intervals.begin(), intervals.end());
        while(cur<size){
            if (intervals[cur][1]>=intervals[cur+1][0]){
                intervals[cur+1][0] = min(intervals[cur][0], intervals[cur+1][0]);
                intervals[cur+1][1] = max(intervals[cur][1], intervals[cur+1][1]);
                intervals.erase(intervals.begin() + index);
                size--;
                cur--;
                index--;
            }
            cur++;
            index++;
        }
        return intervals;
    }
};
