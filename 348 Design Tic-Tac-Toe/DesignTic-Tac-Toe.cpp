class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        r.resize(n,0);
        c.resize(n,0);
        left=right=0;
        win=n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (player==1) {
            r[row]++;
            c[col]++;
            if (row==col) left++;
            if (row+col==win-1) right++;
            if (r[row]==win || c[col]==win || left==win || right==win) return 1;
        }
        else {
            r[row]--;
            c[col]--;
            if (row==col) left--;
            if (row+col==win-1) right--;
            if (r[row]==-win || c[col]==-win || left==-win || right==-win) return 2;
        }
        return 0;
    }
private:
    vector<int> r, c;
    int left=0;
    int right=0;
    int win=0;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */