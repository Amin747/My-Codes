class Solution {
public:
   vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int,int>m;
        for (int i=0; i< nums.size(); i++){
            int temp = target - nums[i];
            if (m.count(temp)) {
                result.push_back(m[temp]);
                result.push_back(i);
                return result;
            }
            else{
                m[nums[i]] = i;
            }
        }
       return result;
    }
};
