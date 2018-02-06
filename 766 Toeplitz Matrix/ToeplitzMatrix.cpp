class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int count=0;
        int limit=max(m,n);
        while (count<limit) {
            if (count<m && check(count,0,matrix,m,n)==false || count<n && check(0,count,matrix,m,n)==false) return false;
            count++;
        }
        return true;
    }
    bool check(int row, int col, vector<vector<int> >& matrix, int m, int n) {
        int value=matrix[row][col];
        while (++row<m && ++col<n) {
            if (value != matrix[row][col]) return false;
        }
        return true;
    }
};