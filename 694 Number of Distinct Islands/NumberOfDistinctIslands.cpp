class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m=grid.size();
        if (m==0) return 0;
        int n=grid[0].size();
        if (n==0) return 0;
        set<vector<pair<int,int> > > s;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                vector<pair<int,int> > t;
                if (helper(i,j,i,j,m,n,grid,t)) s.insert(t);
            }
        }
        return s.size();
    }
    bool helper(int x, int y, int i, int j, int m, int n, vector<vector<int> >& grid, vector<pair<int,int> >& res) {
        if (i<0 || i>=m || j<0 || j>=n || grid[i][j]==0) return false;
        grid[i][j]=0;
        res.push_back(make_pair(i-x,j-y));
        for (int k=0;k<4;k++) {
            helper(x,y,i+dir[k].first,j+dir[k].second,m,n,grid,res);
        }
        return true;
    }
private:
    vector<pair<int,int> > dir={{0,1},{0,-1},{1,0},{-1,0}};
};