class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        vector<int> s(nuts.size(),0);
        vector<int> t(nuts.size(),0);
        int n=0;
        int st=INT_MAX;
        for (int i=0;i<nuts.size();i++)
        {
            s[i]=abs(nuts[i][0]-squirrel[0])+abs(nuts[i][1]-squirrel[1]);
            t[i]=abs(nuts[i][0]-tree[0])+abs(nuts[i][1]-tree[1]);
            st=min(st,s[i]-t[i]);
            n+=t[i];
        }
        return 2*n+st;
    }
};