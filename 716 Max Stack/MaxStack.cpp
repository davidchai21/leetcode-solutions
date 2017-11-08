class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        addStack(x);
    }
    
    int pop() {
        int t=s.top();
        s.pop();
        if (m.top()==t) m.pop();
        return t;
    }
    
    int top() {
        return s.top();
    }
    
    int peekMax() {
        return m.top();
    }
    
    int popMax() {
        int t=m.top();
        m.pop();
        stack<int> tmp;
        while (s.top()!=t) {
            tmp.push(s.top());
            s.pop();
        }
        s.pop();
        while (!tmp.empty()) {
            s.push(tmp.top());
            addStack(tmp.top());
            tmp.pop();
        }
        return t;
    }
private:
    void addStack(int x) {
        if (m.empty() || x>=m.top()) m.push(x);
    }
    stack<int> s,m;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */