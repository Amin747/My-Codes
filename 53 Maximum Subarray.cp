class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> totals[nums.size()];
        int sum = nums[0];
        for (int i=1; i<nums.size(); i++){
            nums[i] = max(nums[i], nums[i]+nums[i-1]);
            if (sum < nums[i]) sum = nums[i];
        }
        return sum;
    }
};
