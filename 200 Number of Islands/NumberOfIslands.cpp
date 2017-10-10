class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        if (m==0) return 0;
        int n=grid[0].size();
        if (n==0) return 0;
        int res=0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]=='1') {
                    res++;
                    helper(grid,i,j);
                }
            }
        }
        return res;
    }
    void helper(vector<vector<char> >& grid, int x, int y) {
        if (x>0 && grid[x-1][y]=='1') {
            grid[x-1][y]='0';
            helper(grid,x-1,y);
        }
        if (x<grid.size()-1 && grid[x+1][y]=='1') {
            grid[x+1][y]='0';
            helper(grid,x+1,y);
        }
        if (y>0 && grid[x][y-1]=='1') {
            grid[x][y-1]='0';
            helper(grid,x,y-1);
        }
        if (y<grid[0].size()-1 && grid[x][y+1]=='1') {
            grid[x][y+1]='0';
            helper(grid,x,y+1);
        }
    }
};