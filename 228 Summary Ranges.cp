class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i=0;
        int end = INT_MIN;
        vector<string>ans;
        string res = "";
        while(i<nums.size()){
            int start = nums[i];
            while (i+1<nums.size() && nums[i+1]==nums[i]+1){
                end = nums[i+1];
                i++;
            }
            if(end!=INT_MIN){
                res+=to_string(start);
                res+="->";
                res+=to_string(end);
                ans.push_back(res);
                res = "";
                end = INT_MIN;
            }
            else{
                res+=to_string(start);
                ans.push_back(res);
                res = "";
            }
            i++;
        }
        return ans;
    }
};
