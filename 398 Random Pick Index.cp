class Solution {
public:
    map<int, vector<int>>m;
    Solution(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++){
            if (!m.count(nums[i])){
               vector<int>temp;
               temp.push_back(i);
               m[nums[i]]= temp;
            }
            else {
                m[nums[i]].push_back(i);
            }
        }
    }
    
    int pick(int target) {
        int size = m[target].size();
        if (size==0) return m[target][size];
        int ans = rand() % size + 0;
        return m[target][ans];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
