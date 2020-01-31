#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
//Given a non-empty array of digits representing a non-negative integer, plus one to the /**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// * };
// */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> answer;
        stack<vector<int>> stk;
        queue<TreeNode*>Q;
        Q.push(root);
        int level = 0;
        if (!root) return {};
        while (!Q.empty()) {
            int level_size = Q.size();
            
            vector<int>temp(level_size);
            int i = 0;
            for (i=0;i<level_size;i++){
                temp[i]=Q.front()->val;
                TreeNode* current = Q.front();
                if (current->left) Q.push(current->left);
                if (current->right) Q.push(current->right);
                Q.pop();
            }
            stk.push(temp);
            level++;
        }

        while (!stk.empty()){
            answer.push_back(stk.top());
            stk.pop();
        }
        return answer;
    }
};

