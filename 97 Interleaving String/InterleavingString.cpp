class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size();
        int n=s2.size();
        if (m+n!=s3.size()) return false;
        vector<vector<bool> > res(m+1,vector<bool>(n+1,false));
        for (int i=0;i<=m;i++)
        {
            for (int j=0;j<=n;j++)
            {
                if (i==0&&j==0) res[i][j]=true;
                else if (i==0) res[i][j]=(s3[j-1]==s2[j-1] && res[i][j-1]);
                else if (i==0) res[i][j]=(s3[i-1]==s1[i-1] && res[i-1][j]);
                else res[i][j]=(s3[i+j-1]==s1[i-1] && res[i-1][j]) || (s3[i+j-1]==s2[j-1] && res[i][j-1]);
            }
        }
        return res[m][n];
    }
};