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
        if (!head || !head->next) return true;
        ListNode* cur = head;
        ListNode* aft = NULL;
        ListNode* pre = NULL;
            
        while (head->next){
            if (head->next->next && head->val == head->next->next->val){
                head = head->next;
                aft = cur->next;
                cur->next = pre;
                pre = cur;
                cur = aft;
                head = head->next;
                if (!head->next && !pre->next) return true;
                if (!head->next || !pre->next) return false;
                while (head && pre){
                    head = head->next;
                    pre = pre->next;
                    if (head->val!=pre->val) return false;
                    if (!head->next && !pre->next) return true;
                    if (!head->next || !pre->next) return false;
                }
            }
            if (head->val == head->next->val){
                head = head->next;
                aft = cur->next;
                cur->next = pre;
                pre = cur;
                cur = aft;
                if (!head->next && !pre->next) return true;
                if (!head->next || !pre->next) return false;
                while (head && pre){
                    head = head->next;
                    pre = pre->next;
                    if (head->val!=pre->val) return false;
                    if (!head->next && !pre->next) return true;
                    if (!head->next || !pre->next) return false;
                }
            }
            else {
                head = head->next;
                aft = cur->next;
                cur->next = pre;
                pre = cur;
                cur = aft;
            }
        }
        return false;
    }
};
