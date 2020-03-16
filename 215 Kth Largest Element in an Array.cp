class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int index = nums.size()-1;
        return nums[index-k+1];
    }
};
