class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int m=M.size();
        if (m==0) return 0;
        int n=M[0].size();
        if (n==0) return 0;
        int r=0;
        const int w=4;
        vector<vector<vector<int> > > res(m+1,vector<vector<int> >(n+2,vector<int>(w,0)));
        for (int i=0;i<m;i++) {
            for (int j=1;j<=n;j++) {
                if (M[i][j-1]) {
                    res[i+1][j][0]=res[i+1][j-1][0]+1;
                    res[i+1][j][1]=res[i][j][1]+1;
                    res[i+1][j][2]=res[i][j-1][2]+1;
                    res[i+1][j][3]=res[i][j+1][3]+1;
                    r=max(r,max(max(res[i+1][j][0],res[i+1][j][1]),max(res[i+1][j][2],res[i+1][j][3])));
                }
            }
        }
        return r;       
    }
};