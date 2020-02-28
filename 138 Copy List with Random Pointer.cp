/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*>m;
        Node* dummy= head;
        
        while (head!=NULL){
            Node* copy = new Node(head->val);
            m[head] = copy;
            head=head->next;
        }
        head = dummy;
        while (head!=NULL){
            m[head]->next = m[head->next];
            m[head]->random = m[head->random];
            head = head->next;
        }
        return m[dummy];
    }
};
