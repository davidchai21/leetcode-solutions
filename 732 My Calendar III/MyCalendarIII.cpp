class MyCalendarThree {
public:
    MyCalendarThree() {}
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int cur=0;
        int res=0;
        for (auto p:m) {
            cur+=p.second;
            if (cur>res) res=cur;
        }
        return res;
    }
private:
    map<int,int> m;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */