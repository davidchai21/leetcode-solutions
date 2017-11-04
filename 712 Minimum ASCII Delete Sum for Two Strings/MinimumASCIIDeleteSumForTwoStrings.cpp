class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int> > res(s1.size()+1,vector<int>(s2.size()+1,0));
        for (int i=1;i<=s1.size();i++) res[i][0]=res[i-1][0]+(int)s1[i-1];
        for (int i=1;i<=s2.size();i++) res[0][i]=res[0][i-1]+(int)s2[i-1];
        for (int i=1;i<=s1.size();i++) {
            for (int j=1;j<=s2.size();j++) {
                if (s1[i-1]==s2[j-1]) res[i][j]=res[i-1][j-1];
                else res[i][j]=min(res[i-1][j]+(int)s1[i-1],res[i][j-1]+(int)s2[j-1]);
            }
        }
        return res[s1.size()][s2.size()];
    }
};