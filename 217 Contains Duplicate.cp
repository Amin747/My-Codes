class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size()==0) return false;
        map<int,int>M;
        for(int i=0; i<nums.size(); i++){
            M[nums[i]]++;
            if (M[nums[i]]>1) return true;
        }
        return false;
    }
};
