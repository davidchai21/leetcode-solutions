class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        if (m<3) return;
        int n=board[0].size();
        if (n<3) return;
        for (int i=0;i<m;i++) {
            if (board[i][0]=='O') update(board,i,0,m,n);
            if (board[i][n-1]=='O') update(board,i,n-1,m,n);
        }
        for (int i=1;i<n-1;i++) {
            if (board[0][i]=='O') update(board,0,i,m,n);
            if (board[m-1][i]=='O') update(board,m-1,i,m,n);
        }
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (board[i][j]=='O') board[i][j]='X';
                else if (board[i][j]=='*') board[i][j]='O';
            }
        }
    }
    void update(vector<vector<char> >& board, int i, int j, int m, int n) {
        board[i][j]='*';
        queue<pair<int,int> > q;
        q.push({i,j});
        while (!q.empty()) {
            pair<int,int> a=q.front();
            q.pop();
            for (int i=0;i<4;i++) {
                int x=a.first+dir[i].first;
                int y=a.second+dir[i].second;
                if (x>=0 && y>=0 && x<m && y<n && board[x][y]=='O') {
                    board[x][y]='*';
                    q.push({x,y});
                }
            }
        }
    }
private:
    vector<pair<int,int> > dir={{0,1},{0,-1},{1,0},{-1,0}};
};