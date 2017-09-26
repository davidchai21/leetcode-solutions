class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m=A.size();
        int n=B[0].size();
        int p=B.size();
        vector<vector<int> > res(m,vector<int>(n,0));
        for (int i=0;i<m;i++){
            for (int j=0;j<p;j++) {
                if (A[i][j]!=0) {
                for (int k=0;k<n;k++) res[i][k]+=A[i][j]*B[j][k];
                }
            }
        }
        return res;
    }
};