class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        auto k=q.end()-1;
        for (int i=0;i<q.size();i++)
        {
            if (k->second==message)
            {
                if (timestamp-k->first<10) return false;
            }
            k--;
        }
        while (!q.empty() && q.front().first+10<timestamp) q.pop_front();
        q.push_back(make_pair(timestamp,message));
        return true;
    }
private:
    deque<pair<int,string> > q;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */