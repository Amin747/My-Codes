class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.size()==0) return 0;
        int max = 0;
        map<int, bool>m;
        for (int i=0; i<nums.size(); i++){
            m[nums[i]] = true;
            if (nums[i]>max){
                max = nums[i];
            }
        }
        
        for (int i=0; i<=nums.size(); i++){
            if (m[i]==false){
                return i;
            }
        }
        return 0;
    }
};
