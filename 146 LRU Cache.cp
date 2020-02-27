struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;
};

class LRUCache {
    public:
    int c;
    map<int, Node*> m;
    Node* head = new Node;
    Node* tail = new Node;
    
    LRUCache(int capacity){
        c = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void add(Node* node) {
        Node* head_next = head->next;
        head->next = node;
        node->next = head_next;
        head_next->prev = node;
        node->prev = head;
    }
    
    void remove(Node* node) {
        Node* n = node->next;
        Node* p = node->prev;
        n->prev = p;
        p->next = n;
    }
    
    int get(int key) {
        if (m.count(key)) {
            remove(m[key]);
            add(m[key]);
            return m[key]->val;
        }
        return -1;
    }
    void put(int key, int value) {
        if(m.count(key)){
            remove(m[key]);
            m[key]->val = value;
            add(m[key]);
        }
        else{
            if (m.size() == c){
                m.erase(tail->prev->key);
                remove(tail->prev);
            }
            
            Node* new_node = new Node;
            new_node->key = key;
            new_node->val = value;
            m[key] = new_node;
            add(new_node);
        }
    }
};
