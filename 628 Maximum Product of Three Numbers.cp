class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int s = nums.size()-1;
        return max(nums[0]*nums[1]*nums[s], nums[s]*nums[s-1]*nums[s-2]);
    }
};
