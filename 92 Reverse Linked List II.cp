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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head==NULL) return NULL;
        int t = 1;
        ListNode* cur = NULL;
        ListNode* prev = NULL;
        ListNode* aft = NULL;
        ListNode* dummy = head;
        ListNode* c1 = NULL;
        
        while (m-1>=t){
            c1 = dummy;
            dummy = dummy->next;
            t++;
        }
        prev=dummy;
        ListNode* c2 = prev;
        int count = 0;
        cur = prev->next;
        
        while (count < n-m){
            aft = cur->next;
            cur->next = prev;
            prev = cur;
            cur = aft;
            count++;
        }
        if (c1) c1->next = prev;
        else head = prev;
        c2->next = cur;
        
        return head;
    }
};
