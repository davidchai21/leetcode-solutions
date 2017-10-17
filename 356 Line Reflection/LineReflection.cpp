class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int a=INT_MAX;
        int b=INT_MIN;
        unordered_map<int,unordered_map<int,bool> > m;
        for (pair<int,int> p:points) {
            a=min(a,p.first);
            b=max(b,p.first);
            m[p.first][p.second]=true;
        }
        int l=a+b;
        for (pair<int,int> p:points) {
            if (!m[l-p.first][p.second]) return false;
        }
        return true;
    }
};