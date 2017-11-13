class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m=board.size();
        if (m==0) return board;
        int n=board[0].size();
        if (n==0) return board;
        while (1) {
            vector<pair<int,int> > t;
            for (int i=0;i<m;i++) {
                for (int j=0;j<n;j++) {
                    if (board[i][j]) {
                        int left=j;
                        int right=j;
                        int up=i;
                        int down=i;
                        while (left>=0 && left>j-3 && board[i][left]==board[i][j]) left--;
                        while (right<n && right<j+3 && board[i][right]==board[i][j]) right++;
                        while (up>=0 && up>i-3 && board[up][j]==board[i][j]) up--;
                        while (down<m && down<i+3 && board[down][j]==board[i][j]) down++;
                        if (right-left>3 || down-up>3) t.push_back(make_pair(i,j));
                    }
                }
            }
            if (t.empty()) break;
            for (pair<int,int> p:t) board[p.first][p.second]=0;
            update(board,m,n);
        }
        return board;
    }
    inline void update(vector<vector<int> >& board, int m, int n) {
        for (int i=0;i<n;i++) {
            int d=m-1;
            int z=m-1;
            while (z>=0 && d>=0) {
                while (z>=0 && board[z][i]) z--;
                d=z;
                while (d>=0 && board[d][i]==0) d--;
                if (z>=0 && d>=0) swap(board[z][i],board[d][i]);
            }
        }
    }
};