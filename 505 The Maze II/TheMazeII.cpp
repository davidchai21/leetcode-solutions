class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (start==destination) return 0;
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<int> > res(m,vector<int>(n,-1));
        res[start[0]][start[1]]=0;
        vector<pair<int,int> > dir={{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int,int> > q;
        q.push(make_pair(start[0],start[1]));
        while (!q.empty()) {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for (int k=0;k<4;k++) {
                int i=x;
                int j=y;
                int step=0;
                while (i+dir[k].first>=0 && i+dir[k].first<m && j+dir[k].second>=0 && j+dir[k].second<n && maze[i+dir[k].first][j+dir[k].second]!=1) {
                    step++;
                    i+=dir[k].first;
                    j+=dir[k].second;
                }
                if (res[i][j]==-1) {
                    res[i][j]=step+res[x][y];
                    q.push({i,j});
                }
                else {
                    if (res[i][j]>res[x][y]+step) {
                        res[i][j]=res[x][y]+step;
                        q.push({i,j});
                    }
                }
            }
        }
        return res[destination[0]][destination[1]];
    }
};