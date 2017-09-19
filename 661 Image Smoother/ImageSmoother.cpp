class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int> > res(M.size(),vector<int>(M[0].size()));
        int m=M.size();
        int n=M[0].size();
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                int t=M[i][j];
                int count=1;
                if (i>=1) {t+=M[i-1][j]; count++;}
                if (j>=1) {t+=M[i][j-1]; count++;}
                if (i<m-1) {t+=M[i+1][j]; count++;}
                if (j<n-1) {t+=M[i][j+1]; count++;}
                if (i>=1 && j>=1) {t+=M[i-1][j-1]; count++;}
                if (i>=1 && j<n-1) {t+=M[i-1][j+1]; count++;}
                if (i<m-1 && j>=1) {t+=M[i+1][j-1]; count++;}
                if (i<m-1 && j<n-1) {t+=M[i+1][j+1]; count++;}
                res[i][j]=t/count;
            }
        }
        return res;
    }
};