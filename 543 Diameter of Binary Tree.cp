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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root==NULL) return 0;
        int dl = DFS(root->left);
        cout << dl << endl;
        int dr = DFS(root->right);
        cout << dr << endl;
        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);
        return max((dl+dr),max(ld,rd));
    }
    
    int DFS(TreeNode* root){
        if (!root) return 0;
        int lr = DFS(root->left);
        int rr = DFS(root->right);
        if (lr>rr){
            return lr+1;
        }
        else{
            return rr+1;
        }
    }
};
