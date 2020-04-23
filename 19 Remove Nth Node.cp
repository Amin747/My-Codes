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
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* slow = new ListNode(-1);
        slow->next = head;
        ListNode* normal = head;
        int i=0;
        while(i<n-1 && normal && normal->next){
            normal = normal->next;
            i++;
        }
        while (normal->next){
            normal = normal->next;
            slow = slow->next;
        }
        if (slow->next){
            if(slow->next==head) head = slow->next->next;
            slow->next = slow->next->next;
        }
        else head=NULL;
        return head;
    }
};
