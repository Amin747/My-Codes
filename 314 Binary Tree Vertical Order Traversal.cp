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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<pair<int, TreeNode*>>pairs;
        queue<pair<int, TreeNode*>>q;
        vector<vector<int>>ans;
        if (!root) return ans;
        q.push(make_pair(0, root));
        while(!q.empty()){
            int s = q.size();
            for (int i=0; i<s; i++){
                if (q.front().second->left){
                    q.push(make_pair(q.front().first-1, q.front().second->left));
                }
                if (q.front().second->right){
                    q.push(make_pair(q.front().first+1, q.front().second->right));
                }
                pairs.push_back(q.front());
                q.pop();
            }
        }
        sort(pairs.begin(), pairs.end());
        int i=0;
        while(i<pairs.size()){
            vector<int>temp;
            temp.push_back(pairs[i].second->val);
            while(i+1<pairs.size() && pairs[i].first==pairs[i+1].first){
                temp.push_back(pairs[i+1].second->val);
                i++;
            }
            ans.push_back(temp);
            i++;
        }
        return ans;
    }
};
