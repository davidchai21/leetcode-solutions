class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if (m==0) return 0;
        int n=matrix[0].size();
        if (n==0) return 0;
        int res=0;
        vector<vector<int> > t(m,vector<int>(n,0));
        for (int i=0;i<m;i++) 
        {
            if (matrix[i][0]=='1')
            {
                t[i][0]=1; res=1;
            }
        }
        for (int i=1;i<n;i++)
        {
            if (matrix[0][i]=='1')
            {
                t[0][i]=1; res=1;
            }
        }
        for (int i=1;i<m;i++)
        {
            for (int j=1;j<n;j++)
            {
                if (matrix[i][j]=='1')
                {
                    t[i][j]=min(min(t[i-1][j-1],t[i-1][j]),t[i][j-1])+1;
                    res=(res<t[i][j])?t[i][j]:res;
                }
                else
                {t[i][j]=0;}
            }
        }
        return res*res;
    }
};