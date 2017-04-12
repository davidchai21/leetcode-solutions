class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        if (n<2) return n;
        a=vector<vector<int> >(n,vector<int>(n,0));
        for (int i=0;i<n;i++) a[i][i]=1;
        for (int i=0;i<n;i++)
        {
            for (int j=i-1;j>=0;j--)
            {
                if (s[i]==s[j]) a[j][i]=2+a[j+1][i-1];
                else
                {
                    a[j][i]=max(a[j+1][i],a[j][i-1]);
                }
            }
        }
        return a[0][n-1];
    }
private:
    vector<vector<int> > a;
};