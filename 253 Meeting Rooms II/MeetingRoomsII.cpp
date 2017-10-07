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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> m;
        for (Interval a:intervals) {
            m[a.start]++;
            m[a.end]--;
        }
        int sum=0;
        int res=0;
        for (auto t:m) {
            sum+=t.second;
            res=max(res,sum);
        }
        return res;
    }
};