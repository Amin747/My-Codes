class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i=0;
        while(i<intervals.size()){
            int left = intervals[i][0];
            int right = intervals[i][1];
            for (int j=i+1; j<intervals.size(); j++){
                if (intervals[j][0] >= right){
                    intervals[i][1] = intervals[j][1];
                    intervals.erase(intervals.begin() + j);
                    i=-1;
                    break;
                }
            }
            i++;
        }
        return intervals.size();
    }
};
