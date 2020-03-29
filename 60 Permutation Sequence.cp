class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int>temp;
        vector<bool>used(nums.size(), false);
        permutations(nums, ans, temp, used);
        return ans;
    }
    
    void permutations(vector<int>nums, vector<vector<int>>&ans, vector<int>&temp, vector<bool>&used){
        if (temp.size()==nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i=0; i<nums.size(); i++){
            if (used[i]==false){
                if (i>0 && nums[i]==nums[i-1] && used[i-1]==false){
                    continue;
                }
                used[i] = true;
                temp.push_back(nums[i]);
                permutations(nums, ans, temp, used);
                used[i]= false;
                temp.pop_back();
            }
        }
    }
};
