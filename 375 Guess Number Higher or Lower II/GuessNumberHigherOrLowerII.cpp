class Solution {
public:
    int getMoneyAmount(int n) {
        if (n<2) return 0;
        vector<vector<int> > res(n+2, vector<int>(n+2,0));
        for (int i=1;i<=n;i++)
        {
            for (int j=i-1;j>=1;j--)
            {
                int t=INT_MAX;
                for (int k=j;k<=i;k++)
                {
                    t=min(t,k+max(res[j][k-1],res[k+1][i]));
                }
                res[j][i]=t;
            }
        }
        return res[1][n];
    }
};