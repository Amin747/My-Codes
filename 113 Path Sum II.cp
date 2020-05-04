class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>ans;
        vector<int>cur;
        find(root, sum, ans, cur);
        return ans;
    }
    
    void find(TreeNode* root, int sum, vector<vector<int>> &ans, vector<int>&cur){
        if(!root) return;
        sum-=root->val;
        cur.push_back(root->val);
        if(!root->left && !root->right){
            if(sum==0) ans.push_back(cur);
            return;
        }
        if(root->left) {
            find(root->left, sum, ans, cur);
            cur.pop_back();
        }
        if(root->right){
            find(root->right, sum, ans, cur);
            cur.pop_back();
        }
    }
};
