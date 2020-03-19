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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if (!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        
        while (!q.empty()){
            int size = q.size();
            for (int i=0; i<size; i++){
                if (q.front()->left){
                    q.push(q.front()->left);
                }
                if (q.front()->right){
                    q.push(q.front()->right);
                }
                if (i==size-1){
                    ans.push_back(q.front()->val);
                }
                q.pop();
            }
        }
        return ans;
    }
};
