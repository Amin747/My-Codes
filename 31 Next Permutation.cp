class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size()==1) return;
        int right = nums.size()-1;
        int left = right-1;
        int min_index = right;
            while(left>=0){
                if(nums[left]<nums[right]){
                    int index = left;
                    int min_swap = right;
                    for (int i=right; i<nums.size(); i++){
                        if (nums[i] < nums[min_swap] && nums[i]>nums[left]){
                            min_swap = i;
                        }
                    }
                    swap(nums[left],nums[min_swap]);
                    sort(nums.begin()+index+1, nums.end());
                    return;
                }
                else{
                    left--;
                    right--;
                    if (right==0) {
                        sort(nums.begin(), nums.end());
                        return;
                    }
                }
            }
    }
};
