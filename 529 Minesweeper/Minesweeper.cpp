class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]]=='M') {
            board[click[0]][click[1]]='X';
            return board;
        }
        helper(board,click[0],click[1]);
        return board;
    }
    inline bool rang(int a, int b, vector<vector<char> > board) {
        return a>=0 && b>=0 && a<board.size() && b<board[0].size();
    }
    void helper(vector<vector<char> >& board, int x, int y) {
        if (!rang(x,y,board)) return;
        int count=0;
        if (board[x][y]=='E') {
            if (rang(x-1,y-1,board) && board[x-1][y-1]=='M') count++;
            if (rang(x-1,y,board) && board[x-1][y]=='M') count++;
            if (rang(x,y-1,board) && board[x][y-1]=='M') count++;
            if (rang(x+1,y-1,board) && board[x+1][y-1]=='M') count++;
            if (rang(x-1,y+1,board) && board[x-1][y+1]=='M') count++;
            if (rang(x,y+1,board) && board[x][y+1]=='M') count++;
            if (rang(x+1,y,board) && board[x+1][y]=='M') count++;
            if (rang(x+1,y+1,board) && board[x+1][y+1]=='M') count++;
            board[x][y]=d[count];
            if (count==0) {
            helper(board,x-1,y-1);
            helper(board,x,y-1);
            helper(board,x-1,y);
            helper(board,x+1,y);
            helper(board,x,y+1);
            helper(board,x-1,y+1);
            helper(board,x+1,y-1);
            helper(board,x+1,y+1);
            }
        }
    }
private:
    const string d="B12345678";
};