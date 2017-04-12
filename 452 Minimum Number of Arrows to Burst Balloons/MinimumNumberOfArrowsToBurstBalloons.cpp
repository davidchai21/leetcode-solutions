class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int n=points.size();
        if (n<2) return n;
        sort(points.begin(),points.end(),[](pair<int,int> a, pair<int,int> b){return a.second==b.second?a.first<b.first:a.second<b.second;});
        int arrow=points[0].second;
        int res=1;
        for (int i=1;i<n;i++)
        {
            if (points[i].first<=arrow) continue;
            arrow=points[i].second;
            res++;
        }
        return res;
    }
};