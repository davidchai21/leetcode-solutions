class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        vector<pair<int,int> > direction(4);
        direction[0]=make_pair(0,-1);
        direction[1]=make_pair(1,0);
        direction[2]=make_pair(0,1);
        direction[3]=make_pair(-1,0);
        int m=rooms.size();
        if (m==0) return;
        int n=rooms[0].size();
        if (n==0) return;
        queue<pair<int,int> > q;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (rooms[i][j]==0) q.push(make_pair(i,j));
            }
        }
        while (!q.empty()) {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for (auto d:direction) {
                int r=x+d.first;
                int c=y+d.second;
                if (r<0 || r>=m || c<0 || c>=n || rooms[r][c]!=2147483647) continue;
                rooms[r][c]=rooms[x][y]+1;
                q.push(make_pair(r,c));
            }
        }
    }
};