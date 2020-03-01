class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        vector<int>uniqes;
        for (int i=0; i<nums.size(); i++){
            if (!m.count(nums[i])) uniqes.push_back(nums[i]);
            m[nums[i]]++;
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        vector<int>ans;
        int rem;
        while (k>0){
            int temp = 0;
            for (int i=0; i< uniqes.size(); i++){
                if (m[uniqes[i]])
                    if (m[uniqes[i]]>=temp){
                        temp = m[uniqes[i]];
                        rem = uniqes[i];
                    }
                
            }
            ans.push_back(rem);
            m[rem]=0;
            k--;
        }
        return ans;
    }
};
