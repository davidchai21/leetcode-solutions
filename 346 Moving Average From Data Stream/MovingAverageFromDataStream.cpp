class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        w=size;
    }
    
    double next(int val) {
        if (q.size()==w)
        {
            s-=q.front();
            q.pop();
        }
        s+=val;
        q.push(val);
        return s/q.size();
    }
private:
    int w=0;
    double s=0;
    queue<int> q;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */