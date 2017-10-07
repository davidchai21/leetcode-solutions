class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        if (m==0) return;
        int n=board[0].size();
        if (n==0) return;
        countlive(board,m,n);
        update(board,m,n);
    }
    void countlive(vector<vector<int> >& board, int m, int n) {
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                int l=0;
                for (int a=max(i-1,0);a<min(i+2,m);a++) {
                    for (int b=max(j-1,0);b<min(j+2,n);b++) {
                        if (board[a][b]%2) l++;
                    }
                }
                l-=board[i][j]%2;
                if (board[i][j]%2) {
                    if (l==2 || l==3) board[i][j]=3; 
                }
                else {
                    if (l==3) board[i][j]=2; 
                }
            }
        }
    }
    void update(vector<vector<int> >& board, int m, int n) {
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                board[i][j]>>=1;
            }
        }
    }
};