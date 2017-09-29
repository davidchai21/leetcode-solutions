class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m=matrix.size();
        if (m==0) return res;
        int n=matrix[0].size();
        if (n==0) return res;
        vector<vector<int> > t(m+n-1);
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                t[i+j].push_back(matrix[i][j]);
            }
        }
        for (int i=0;i<m+n-1;i++) {
            if (i%2==0) {
                res.insert(res.end(),t[i].rbegin(),t[i].rend());
            }
            else {res.insert(res.end(),t[i].begin(),t[i].end());}
        }
        return res;
    }
};