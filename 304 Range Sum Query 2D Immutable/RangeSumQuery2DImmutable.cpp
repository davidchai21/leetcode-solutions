class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        a=vector<vector<int> >(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        for (int i=1;i<=matrix.size();i++)
        {
            for (int j=1;j<=matrix[0].size();j++)
            {
                a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+matrix[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return a[row2+1][col2+1]-a[row1][col2+1]-a[row2+1][col1]+a[row1][col1];
    }
private:
    vector<vector<int> > a;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */