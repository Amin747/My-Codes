class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>right(nums.size());
        vector<int>left(nums.size());
        int r = 1;
        int l = 1;
        
        for(int i=0; i<nums.size(); i++){
            right[i] = r;
            r = nums[i]*r;
        }
        for(int i=nums.size()-1; i>=0; i--){
            left[i] = l;
            l = nums[i]*l;
        }
        for (int i=0; i<right.size();i++){
            right[i] = right[i] * left[i];
        }
        return right;
    }
};
