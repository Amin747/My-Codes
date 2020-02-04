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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        queue<TreeNode*>Q;
        Q.push(root);
        int level = 0;
        while (!Q.empty()){
            int Qsize = Q.size();
            int max = Q.front()->val;
            for (int i=0; i<Qsize; i++){
                TreeNode* current = Q.front();
                if (Q.front()->val > max){
                    max = Q.front()->val;
                }
                if (current->left) Q.push(current->left);
                if (current->right) Q.push(current->right);
                Q.pop();
            }
            ans.push_back(max);
            level++;
        }
        return ans;
    }
};
