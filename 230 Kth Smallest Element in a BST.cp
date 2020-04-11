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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue <int, vector<int>, greater<int>> pq;
        pq.push(root->val);
        dfs(root, pq);
        while (k!=1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
    
    void dfs(TreeNode* root, priority_queue <int, vector<int>, greater<int>> &pq){
        if(!root) return;
        if (root->left){
            pq.push(root->left->val);
            dfs(root->left, pq);
        }
        if (root->right){
            pq.push(root->right->val);
            dfs(root->right, pq);
        }
    }
};
