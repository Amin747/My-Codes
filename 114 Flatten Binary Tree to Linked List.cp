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
    void flatten(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return;
        queue<TreeNode*>q;
        TreeNode* head = root;
        q.push(root);
        dfs(root, q);
        while(!q.empty()){
            head->right = q.front();
            head = head->right;
            head->left = NULL;
            q.pop();
        }
        
    }
    void dfs(TreeNode* root, queue<TreeNode*>&q){
        if (!root) return;
        if (root->left){
            q.push(root->left);
            dfs(root->left, q);
        }
        if (root->right){
            q.push(root->right);
            dfs(root->right, q);
        }
    }
};
