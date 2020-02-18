/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int>vec;
        
        if(head==NULL || head->next==NULL){
            return true;
        }
        vec.push_back(head->val);
        head = head->next;
    
        while(head){
            vec.push_back(head->val);
            head = head->next;
        }
        int start = 0;
        int end = vec.size()-1;
        while (start<=end){
            if (vec[start]==vec[end]){
                start++;
                end--;
            }
            else return false;
        }
        return true;
    }
};
