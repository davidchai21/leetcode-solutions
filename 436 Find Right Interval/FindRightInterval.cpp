/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int,int> m;
        int n=intervals.size();
        for (int i=0;i<n;i++) m[intervals[i].start]=i;
        vector<int> res(n,-1);
        for (int i=0;i<n;i++) {
            auto it=m.lower_bound(intervals[i].end);
            if (it!=m.end()) res[i]=it->second;
        }
        return res;
    }
};