class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>cur;
        sort(candidates.begin(), candidates.end());
        helper(cur, candidates, target, 0);
        return ans;
    }
    
    void helper(vector<int>&cur, vector<int>candidates, int target, int index){
        if(target<0) return;
        if(target==0) {
            ans.push_back(cur);
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(target<candidates[i]) return;
            if(i-1>=0 && candidates[i]==candidates[i-1] && i>index) continue;
            cur.push_back(candidates[i]);
            helper(cur, candidates, target-candidates[i], i+1);
            cur.pop_back();
        }
    }
};
