class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        if (m==0) return n; if (n==0) return m;
        vector<vector<int> > res(m+1,vector<int>(n+1,0));
        for (int i=0;i<=m;i++) res[i][0]=i;
        for (int i=1;i<=n;i++) res[0][i]=i;
        for (int i=1;i<=m;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (word1[i-1]==word2[j-1]) res[i][j]=res[i-1][j-1];
                else
                {
                    res[i][j]=min(res[i-1][j-1],min(res[i-1][j],res[i][j-1]))+1;
                }
            }
        }
        return res[m][n];
    }
};