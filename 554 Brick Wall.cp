class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int>m;
        int ans= 0;
        vector<int>sums;
        for (int i=0; i<wall.size(); i++){
            int sum = 0;
            for (int j=0; j<wall[i].size()-1; j++){
                sum += wall[i][j];
                m[sum]++;
                sums.push_back(sum);
            }
        }
        for(int i=0; i<sums.size(); i++){
            ans = max(ans, m[sums[i]]);
        }
        return wall.size()-ans;
    }
};
