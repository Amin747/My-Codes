/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        int level = 0;
        
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int>temp;
            level++;
            for (int i=0; i<s; i++){
                if (q.front()->left){
                    q.push(q.front()->left);
                }
                if (q.front()->right){
                    q.push(q.front()->right);
                }
                temp.push_back(q.front()->val);
                q.pop();
            }
            if (level%2==0){
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
            }
            else
                ans.push_back(temp);
        }
        return ans;
    }
};
