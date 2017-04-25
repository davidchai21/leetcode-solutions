class Solution {
public:
    int numDistinct(string s, string t) {
        if (s==t || t=="") return 1;
        int m=s.size();
        int n=t.size();
        vector<vector<int> > res(n+1,vector<int>(m+1,0));
        for (int i=0;i<=m;i++) res[0][i]=1;
        for (int i=1;i<=n;i++)
        {
            int k=1;
            for (int j=i;j<=m;j++)
            {
                if (s[j-1]==t[i-1])
                {
                    res[i][j]=res[i-1][j-1]+res[i][j-1];
                }
                else res[i][j]=res[i][j-1];
            }
        }
        return res[n][m];
    }
};