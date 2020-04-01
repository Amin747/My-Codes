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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        if (!isLeaf(root)) ans.push_back(root->val);
        
        TreeNode* l = root->left;
        while (l!=NULL){
            if (!isLeaf(l)){
                ans.push_back(l->val);
            }
            if (l->left){
                l = l->left;
            }
            else{
                l = l->right;
            }
        }
        addLeaves(root, ans);
        
        stack<int>st;
        TreeNode* r = root->right;
        while(r!=NULL){
            if(!isLeaf(r)){
                st.push(r->val);
            }
            if(r->right){
                r=r->right;
            }
            else{
                r = r->left;
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
    
    bool isLeaf(TreeNode* root){
        return root->left==NULL && root->right==NULL;
    }
    
    void addLeaves(TreeNode* root, vector<int>&ans){
        if(isLeaf(root)){
            ans.push_back(root->val);
        }
        if(root->left){
            addLeaves(root->left, ans);
        }
        if(root->right){
            addLeaves(root->right, ans);
        }
    }
};
