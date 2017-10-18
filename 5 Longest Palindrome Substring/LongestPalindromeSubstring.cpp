class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if (n<2) return s;
        vector<vector<bool> > res(n,vector<bool>(n,false));
        int x=0;
        int y=0;
        for (int i=n-1;i>=0;i--) {
            for (int j=i;j<n;j++) {
                if (i==j) res[i][j]=true;
                else if (i==j-1) res[i][j]=s[i]==s[j];
                else {
                    if (s[i]==s[j]) res[i][j]=res[i+1][j-1];
                }
                if (res[i][j] && y-x<j-i) {
                    x=i;
                    y=j;
                }
            }
        }
        return s.substr(x,y-x+1);
    }
};