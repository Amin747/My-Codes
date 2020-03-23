/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        Node* p = head;
        while (p){
            if (!p->child){
                p = p->next;
                continue;
            }
            if (p->child){
                Node* temp = p->child;
                while (temp->next){
                    temp = temp->next;
                }
                temp->next = p->next;
                if (p->next) p->next->prev = temp;
                p->next = p->child;
                p->child->prev = p;
                p->child = NULL;
            }
        }
        return head;
    }
};
