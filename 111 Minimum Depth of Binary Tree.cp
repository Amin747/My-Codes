#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

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
    int minDepth(TreeNode* root) {
        if (!root) return NULL;
        if (!root->left && !root->right) return 1;
        queue<TreeNode*>Q;
        Q.push(root);
        int level =1;
        while (!Q.empty()){
            int size = Q.size();
            for(int i=0; i<size; i++){
                if (Q.front()->left) {
                    Q.push(Q.front()->left);
                }
                else {
                    if (!Q.front()->left && !Q.front()->right){
                    return level;
                    }
                }
                if (Q.front()->right) {
                    Q.push(Q.front()->right);
                }
                else {
                    if (!Q.front()->left && !Q.front()->right){
                    return level;
                    }
                }
            Q.pop();
            }
            level++;
        }
        return NULL;
    }
};



