class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size()==0) return 0;
        int ans = INT_MAX;
        int cur = 0;
        queue<int>q;
        int i = 0;
        while (i<nums.size() && cur<s){
            cur+=nums[i];
            q.push(nums[i]);
            while (cur>=s){
                int s = q.size();
                ans = min(ans, s);
                cur-=q.front();
                q.pop();
            }
            i++;
        }
        if (q.size()==nums.size()) return 0;
        return ans;
    }
};
