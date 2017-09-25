class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter():time(300,0), hits(300,0) {}
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int t=timestamp%300;
        if (timestamp!=time[t]) {
            time[t]=timestamp;
            hits[t]=1;
        }
        else hits[t]++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int res=0;
        for (int i=0;i<300;i++) {
            if (time[i]+300>timestamp) res+=hits[i];
        }
        return res;
    }
private:
    vector<int> time;
    vector<int> hits;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */