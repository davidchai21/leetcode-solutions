class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m=grid.size();
        if (m==0) return 0;
        int n=grid[0].size();
        if (n==0) return 0;
        vector<int> row,col;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]) {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        nth_element(row.begin(),row.begin()+row.size()/2,row.end());
        nth_element(col.begin(),col.begin()+col.size()/2,col.end());
        int x=row[row.size()/2];
        int y=col[col.size()/2];
        int res=0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]) res+=abs(x-i)+abs(y-j);
            }
        }
        return res;
    }
};