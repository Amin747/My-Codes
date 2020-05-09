class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>vec;
        while(head){
            vec.push_back(head->val);
            head = head->next;
        }
        int l = 0;
        int r = vec.size()-1;
        return make_tree(vec, l, r);
    }
    
    TreeNode* make_tree(vector<int>vec, int l, int r){
        if(l>r) return NULL;
        TreeNode* root = new TreeNode();
        int mid = l-(l-r)/2;
        root->val = vec[mid];
        root->left = make_tree(vec, l, mid-1);
        root->right = make_tree(vec, mid+1, r);
        return root;
    }
};
