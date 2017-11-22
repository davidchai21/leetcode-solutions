class MyCalendarTwo {
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        for (int i=0;i<a.size();i++) {
            if (start>=a[i].second || end<=a[i].first) continue;
            else return false;
        }
        for (int i=0;i<b.size();i++) {
            if (start>=b[i].second || end<=b[i].first) continue;
            else a.push_back(make_pair(max(b[i].first,start),min(b[i].second,end)));
        }
        b.push_back(make_pair(start,end));
        return true;
    }
private:
    vector<pair<int,int> > a,b;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */