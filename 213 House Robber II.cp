class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==0) return 0;
        if (nums.size()==1) return nums[0];
        vector<int>nums2 = nums;
        nums2.pop_back();
        vector<int>first = nums2;
        nums.erase(nums.begin()+ 0);
        vector<int>last = nums;
        return max(robI(first),robI(last));
    }
    
    int robI(vector<int>& nums) {
        int with=0;
        int without=0;
        vector<int>wo(nums.size());
        
        for(int i=0; i<nums.size(); i++){
            wo[i] = without;
            without = max(with, without);
            with = wo[i]+nums[i];
        }
        return max(with, without);
    }
};
