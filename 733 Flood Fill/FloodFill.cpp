class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc]==newColor) return image;
        vector<pair<int,int> > dir={{0,1},{0,-1},{1,0},{-1,0}}; 
        int r=image.size();
        int c=image[0].size();
        queue<pair<int,int> > q;
        int old=image[sr][sc];
        q.push(make_pair(sr,sc));
        while (!q.empty()) {
            int x=q.front().first;
            int y=q.front().second;
            image[x][y]=newColor;
            q.pop();
            for (int i=0;i<4;i++) {
                if (x+dir[i].first>=0 && x+dir[i].first<r && y+dir[i].second>=0 && y+dir[i].second<c && image[x+dir[i].first][y+dir[i].second]==old) {
                    q.push(make_pair(x+dir[i].first,y+dir[i].second));
                }
            }
        }
        return image;
    }
};