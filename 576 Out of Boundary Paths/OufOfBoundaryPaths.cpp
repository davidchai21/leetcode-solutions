class Solution {
public:
    int findPaths(int m, int n, int N, int ii, int jj) {
        vector<vector<vector<unsigned int> > > res(N+1,vector<vector<unsigned int> >(m,vector<unsigned int>(n,0)));
        for (int k=1;k<=N;k++) {
            for (int i=0;i<m;i++) {
                for (int j=0;j<n;j++) {
                    res[k][i][j]+=i==0?1:res[k-1][i-1][j];
                    res[k][i][j]+=i==m-1?1:res[k-1][i+1][j];
                    res[k][i][j]+=j==0?1:res[k-1][i][j-1];
                    res[k][i][j]+=j==n-1?1:res[k-1][i][j+1];
                    res[k][i][j]%=base;
                }
            }
        }
        return res[N][ii][jj];
    }
private:
    const int base=1000000007;
};