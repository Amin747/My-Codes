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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL) return NULL;
        if (root->val == p->val || root->val==q->val) return root;
        TreeNode* left_search = lowestCommonAncestor(root->left, p, q);
        TreeNode* right_search = lowestCommonAncestor(root->right, p, q);
        if (left_search==NULL) return right_search;
        if (right_search==NULL) return left_search;
        if (left_search!=NULL && right_search!=NULL) return root;
        return root;
    }
};
