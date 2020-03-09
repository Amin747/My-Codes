class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        helper(ans, "", 0, 0, n);
        return ans;
    }
    
    void helper(vector<string> &ans, string cur, int open, int close, int max){
        if (cur.length()==max*2){
            ans.push_back(cur);
            return;
        }
        
        if (open<max) helper(ans, cur + '(', open+1, close, max);
        if (close<open) helper(ans, cur + ')', open, close+1, max);
    }
};
