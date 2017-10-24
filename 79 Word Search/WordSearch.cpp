class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return false;
        m=board.size();
        if (m==0) return false;
        n=board[0].size();
        if (n==0) return false;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (helper(word,0,board,i,j)) return true;
            }
        }
        return false;
    }
    bool helper(string word, int k, vector<vector<char> >& board, int i, int j) {
        if (i<0 || j<0 || i>=m || j>=n || board[i][j]!=word[k]) return false;
        if (k==word.size()-1) return true;
        char t=board[i][j];
        board[i][j]='\0';
        if (helper(word,k+1,board,i+1,j) || helper(word,k+1,board,i,j+1) ||helper(word,k+1,board,i-1,j) ||helper(word,k+1,board,i,j-1)) return true;
        board[i][j]=t;
        return false;
    }
private:
    int m,n;
};