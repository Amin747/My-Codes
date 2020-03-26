class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        vector<int>ans;
        if (nums.size()==0) return {-1,-1};
        if (nums.size()==1 && nums[0]==target) return {0,0};
        while (left<=right){
            int mid = (left+right)/2;
            if (target==nums[mid]){
                ans.push_back(mid);
                int mid_left = mid-1;
                int mid_right = mid+1;
                while(mid_left >= 0 && nums[mid_left]==target){
                    ans.push_back(mid_left);
                    mid_left--;
                }
                while(mid_right <nums.size() && nums[mid_right]==target){
                    ans.push_back(mid_right);
                    mid_right++;
                }
                if (ans.size()==1) ans.push_back(ans[0]);
                sort(ans.begin(), ans.end());
                while (ans.size()>2){
                    ans.erase(ans.begin() + 1);
                }
                return ans;
            }
            else if (target > nums[mid]){
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        if (ans.size()==0) return {-1,-1};
        return ans;
    }
};
