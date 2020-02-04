class MyQueue {
public:
    
    stack<int> st1;
    stack<int> st2;
    
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int r = peek();
        st2.pop();
        return r;
    }
    
    /** Get the front element. */
    int peek() {
        
        if (st2.empty()) {
          
            while (st1.empty() == false) {
                st2.push(st1.top());
                st1.pop();
            }
            
            
        }
        
        return st2.top();
    }
    
    bool empty() {
        
        return st1.empty() && st2.empty();
    }
};

