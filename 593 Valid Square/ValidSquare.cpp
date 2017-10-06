class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if (same(p1,p2,p3,p4)) return false;
        vector<vector<int> > s(4);
        s[1]=p1;
        s[2]=p2;
        s[3]=p3;
        s[0]=p4;
        sort(s.begin(),s.end(),[](vector<int> a, vector<int> b){return a[0]<b[0] || a[0]==b[0] && a[1]<b[1];});
        swap(s[2],s[3]);
        return good(s[0],s[1],s[2]) && good(s[1],s[2],s[3]) && good(s[2],s[3],s[0]) && good(s[3],s[0],s[1]);
    }
    bool same(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return (p1==p2 || p1==p3 || p1==p4 || p2==p3 || p2==p4 || p3==p4);
    }
    bool good(vector<int>& p1, vector<int>& p2, vector<int>& p3) {
        vector<int> a=p1;
        vector<int> b=p2;
        a[0]-=p2[0];
        a[1]-=p2[1];
        b[0]-=p3[0];
        b[1]-=p3[1];
        return (a[0]*b[0]+a[1]*b[1]==0 && a[0]*a[0]+a[1]*a[1]==b[0]*b[0]+b[1]*b[1]);
    }
};