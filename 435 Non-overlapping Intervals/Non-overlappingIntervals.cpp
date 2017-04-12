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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int n=intervals.size();
        if (n<2) return 0;
        int res=0;
        sort(intervals.begin(),intervals.end(),[](Interval a,Interval b){return a.end==b.end?a.start<b.start:a.end<b.end;});
        int index=intervals[0].end;
        for (int i=1;i<n;i++)
        {
            if (index>intervals[i].start)
            {
                res++;
                continue;
            }
            else
            {
                index=intervals[i].end;
            }
        }
        return res;
    }
};