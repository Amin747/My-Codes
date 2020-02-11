class MaxStack {
public:
    vector<int>vec;
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        vec.push_back(x);
    }
    
    int pop() {
        int p = vec[vec.size()-1];
        vec.pop_back();
        return p;
    }
    
    int top() {
        return vec[vec.size()-1];
    }
    
    int peekMax() {
        int m = -10000000;
        for (int i=0; i<vec.size();i++){
            if (vec[i]>m)
                m = vec[i];
        }
        return m;
    }
    
    int popMax() {
        int n = -10000000;
        int dex = 0;
        int count = 1;
        for (int i=0; i<vec.size();i++){
            if (vec[i]>n){
                n = vec[i];
                dex = i;
            }
        }
        for (int i=vec.size()-1; i>=0; i--){
            if (vec[i]==n){
                vec.erase(vec.begin() + i);
                return n;
            }
        }
        return n;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
