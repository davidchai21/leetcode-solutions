class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        //stack<int> s,t;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (!t.empty())
        {
            s.push(t.top());
            t.pop();
        }
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while (!s.empty())
        {
            t.push(s.top());
            s.pop();
        }
        int a=t.top();
        t.pop();
        return a;
    }
    
    /** Get the front element. */
    int peek() {
        while (!s.empty())
        {
            t.push(s.top());
            s.pop();
        }
        return t.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty() && t.empty();
    }
private:
    stack<int> s,t;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */