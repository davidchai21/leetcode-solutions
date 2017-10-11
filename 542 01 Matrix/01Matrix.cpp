class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if (m==0) return matrix;
        int n=matrix[0].size();
        if (n==0) return matrix;
        queue<pair<int,int> > q;
        vector<vector<int> > res(m,vector<int>(n,INT_MAX));
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (matrix[i][j]==0) res[i][j]=0;
                else if (matrix[i][j]==1 && (i>0 && matrix[i-1][j]==0 || j>0 && matrix[i][j-1]==0 || i<m-1 && matrix[i+1][j]==0 || j<n-1 && matrix[i][j+1]==0)) {
                    q.push({i,j});
                    res[i][j]=1;
                }
            }
        }
        while (!q.empty()) {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if (x>0 && res[x][y]+1<res[x-1][y]) {
                res[x-1][y]=res[x][y]+1;
                q.push({x-1,y});
            }
            if (y>0 && res[x][y]+1<res[x][y-1]) {
                res[x][y-1]=res[x][y]+1;
                q.push({x,y-1});
            }
            if (x<m-1 && res[x][y]+1<res[x+1][y]) {
                res[x+1][y]=res[x][y]+1;
                q.push({x+1,y});
            }
            if (y<n-1 && res[x][y]+1<res[x][y+1]) {
                res[x][y+1]=res[x][y]+1;
                q.push({x,y+1});
            }
        }
        return res;
    }
};