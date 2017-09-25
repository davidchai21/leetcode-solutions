class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        if (n<2) return n;
        vector<vector<bool> > res(n,vector<bool>(n,false));
        int count=0;
        for (int i=n-1;i>=0;i--)
        {
            for (int j=i;j<n;j++)
            {
                if (i==j) {res[i][j]=true;}
                else if (i+1==j) {res[i][j]=s[i]==s[j];}
                else {
                    if (s[j]==s[i]) res[i][j]=res[i+1][j-1];
                }
                if (res[i][j]) count++;
            }
        }
        return count;
    }
};