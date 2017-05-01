class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0,j=0;
        int count=0;
        while (1)
        {
            for (int k=j;k<n-j;k++)
            {
                res.push_back(matrix[i][k]);
                count++;
            }
            if (count>=m*n) break;
            for (int k=i+1;k<m-i;k++)
            {
                res.push_back(matrix[k][n-1-j]);
                count++;
            }
            if (count>=m*n) break;
            for (int k=n-j-2;k>=j;k--)
            {
                res.push_back(matrix[m-i-1][k]);
                count++;
            }
            if (count>=m*n) break;
            for (int k=m-i-2;k>i;k--)
            {
                res.push_back(matrix[k][j]);
                count++;
            }
            i++; j++;
            if (count>=m*n) break;
        }
        return res;
    }
};