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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        map<TreeNode*, TreeNode*> parents;
        map<TreeNode*, bool>visited;
        vector<int> res;
        dfs(root, parents, target);
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        
        while(!q.empty() && K >= 0){
            int size = q.size();
            for(int i=0; i<size; i++){
                if(K == 0) {
                    while(!q.empty()){
                        res.push_back(q.front()->val);
                        q.pop();
                    }
                    return res;
                }
                if(!visited.count(parents[q.front()]) && parents[q.front()]){
                    q.push(parents[q.front()]);
                    visited[parents[q.front()]]=true;
                }
                if(!visited.count(q.front()->left) && q.front()->left) {
                    q.push(q.front()->left);
                    visited[q.front()->left]=true;
                }
                if(!visited.count(q.front()->right) && q.front()->right) {
                    q.push(q.front()->right);
                    visited[q.front()->right]=true;
                }
                q.pop();
            }
            K--;
        }
        return res;
    }
    void dfs(TreeNode* root, map<TreeNode*, TreeNode*> &parents, TreeNode* target){
        if(!root || (root == target)) return;
    
        if(root->left){
            parents[root->left] = root;
            dfs(root->left, parents, target);
        }
        if(root->right){
            parents[root->right] = root;
            dfs(root->right, parents, target);
        }
    }
};
