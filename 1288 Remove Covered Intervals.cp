class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int c = intervals[0][0];
        int d = intervals[0][1];
        int covered = 0;
        int i=1;
        while(i<intervals.size()){
            int a = intervals[i][0];
            int b = intervals[i][1];
            if(a>=c && b<=d) {
                covered++;
            }
            else{
                c=a;
                d=b;
            }
            i++;
        }
        return intervals.size()-covered;
    }
};
