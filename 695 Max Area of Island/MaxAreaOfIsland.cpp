class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        int m=grid.size();
        if (m==0) return res;
        int n=grid[0].size();
        if (n==0) return res;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]) helper(grid,i,j,res,m,n);
            }
        }
        return res;
    }
    void helper(vector<vector<int> >& grid, int x, int y, int& res, int m, int n) {
        queue<pair<int,int> > q;
        int size=0;
        q.push(make_pair(x,y));
        while (!q.empty()) {
            int a=q.front().first;
            int b=q.front().second;
            q.pop();
            if (grid[a][b]) {
                size++;
                grid[a][b]=0;
                for (int i=0;i<4;i++) {
                    if (a+dir[i].first>=0 && a+dir[i].first<m && b+dir[i].second>=0 && b+dir[i].second<n && grid[a+dir[i].first][b+dir[i].second]) q.push(make_pair(a+dir[i].first,b+dir[i].second));
                }
            }
        }
        res=max(res,size);
    }
private:
    vector<pair<int,int> > dir={{0,1},{0,-1},{1,0},{-1,0}}; 
};