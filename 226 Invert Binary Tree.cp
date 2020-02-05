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
    TreeNode* invertTree(TreeNode* root) {
        if (root==NULL) return NULL;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            int Qsize = Q.size();
            for (int i=0; i<Qsize; i++){
                if (Q.front()->right) Q.push(Q.front()->right);
                if (Q.front()->left) Q.push(Q.front()->left);
                TreeNode* temp1 = Q.front()->left;
                TreeNode* temp2 = Q.front()->right;
                Q.front()->right = temp1;
                Q.front()->left = temp2;
                Q.pop();
            }
        }
    return root;
    }
};
