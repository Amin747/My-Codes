class Solution {
public:
    void sortColors(vector<int>& nums) {
        int mid = 0;
        int start = 0;
        int end = nums.size()-1;
        
        while (mid<=end && start<end){
            if (nums[mid]==0){
                int temp = nums[start];
                nums[mid] = temp;
                nums[start] = 0;
                mid++;
                start++;
            }
            else if (nums[mid]==2) {
                int temp = nums[end];
                nums[mid] = temp;
                nums[end] = 2;
                end--;
            }
            else mid++;
        }
    }
};
