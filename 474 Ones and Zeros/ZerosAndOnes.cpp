class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > res(m+1,vector<int>(n+1,0));
        for (int k=0;k<strs.size();k++) {
            int zero=0;
            int one=0;
            for (char a:strs[k]) {
                if (a=='0') zero++;
                else if (a=='1') one++;
            }
            for (int i=m;i>=zero;i--) {
                for (int j=n;j>=one;j--) {
                    res[i][j]=max(res[i][j],res[i-zero][j-one]+1);
                }
            }
        }
        return res[m][n];
    }
};