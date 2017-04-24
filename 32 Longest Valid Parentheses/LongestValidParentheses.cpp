class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int res=0;
        vector<int> m(n+1,0);
        for (int i=1;i<=n;i++)
        {
            if (s[i-1]=='(') m[i]=0;
            else
            {
                if (s[i-2]=='(')
                {
                    m[i]=2+m[i-2];
                    res=max(res,m[i]);
                }
                else
                {
                    if (s[i-2-m[i-1]]=='(') m[i]=m[i-2-m[i-1]]+2+m[i-1];
                    res=max(res,m[i]);
                }
            }
        }
        return res;
    }
};