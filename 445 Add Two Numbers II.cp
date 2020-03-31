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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>st1;
        stack<int>st2;
        
        ListNode* res = new ListNode(0);
        
        while(l1){
            st1.push(l1->val);
            l1=l1->next;
        }
        
        while(l2){
            st2.push(l2->val);
            l2=l2->next;
        }
        
        int carry = 0;
        while(!st1.empty() || !st2.empty()){
            int n1;
            if (!st1.empty()){
                n1 = st1.top();
            }
            else n1=0;
            
            int n2;
            if (!st2.empty()){
                n2 = st2.top();
            }
            else n2=0;
            
            int sum = carry+n1+n2;
            carry = sum/10;
            sum = sum%10;
            
            ListNode* cur = new ListNode(sum);
            cur->next = res->next;
            res->next = cur;
            
            if(!st1.empty()) st1.pop();
            if(!st2.empty()) st2.pop();
        }
        if (carry){
            ListNode* temp= new ListNode(carry);
            temp->next = res->next;
            res->next = temp;
        }
        return res->next;
    }
};
