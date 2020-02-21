class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        queue<vector<int>> q;
        vector<int>temp={};
        ans.push_back(temp);
        if(nums.size()==0) return ans;
        q.push(temp);
        int n = 0;
        
        while (n<nums.size()){
            int size = q.size();
            for (int i=0; i<size; i++){
                q.push(q.front());
                q.front().push_back(nums[n]);
                q.push(q.front());
                ans.push_back(q.front());
                q.pop();
            }
            n++;
        }
        return ans;
    }
};
