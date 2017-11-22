class MyCalendar {
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto cur=m.lower_bound(start);
        if (cur!=m.end() && end>cur->first) return false;
        if (cur!=m.begin() && (--cur)->second>start) return false;
        m[start]=end;
        return true;
    }
private:
    map<int,int> m;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */