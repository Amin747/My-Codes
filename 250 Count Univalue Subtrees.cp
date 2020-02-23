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
    int count =0;
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return 0;
        if (isUnival(root)) count++;
        countUnivalSubtrees(root->left);
        countUnivalSubtrees(root->right);
        return count;
    }
        
    
    bool isUnival(TreeNode* root){
        if (!root) return true;
        if (root->left == NULL && root->right == NULL) return true;
        if (root->left) {
            if (root->val != root->left->val) return false;
        }
        if (root->right) {
            if (root->val != root->right->val) return false;
        }
        return isUnival(root->left) && isUnival(root->right);
    }
};
