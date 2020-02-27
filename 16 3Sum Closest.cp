class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mindif = INT_MAX;
        int ans;
    
        for (int i=0; i<nums.size()-2; i++){
            int low = i+1;
            int high = nums.size()-1;
            while (low<high){
                int sum = nums[i]+nums[low]+nums[high];
                if (mindif > min(abs(sum-target), abs(mindif))) ans = sum;
                mindif = min(abs(sum-target), abs(mindif));
                if (mindif==0) return target;
                else if(sum<target) low++;
                else if(sum>target) high--;
            }
        }
        return ans;
    }
};
