class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if (s[0]=='0') return 0;
        if (n<2) return n;
        vector<int> res(n+1,0);
        res[0]=1;
        res[1]=1;
        for (int i=2;i<=n;i++)
        {
            if (s[i-1]=='0')
            {
                if (s[i-2]>'2' || s[i-2]=='0') return 0;
                else res[i]=res[i-2];
            }
            else
            {
                if (s[i-2]=='0') res[i]=res[i-2];
                else
                {
                    if (10*(s[i-2]-'0')+s[i-1]-'0'>26) res[i]=res[i-1];
                    else res[i]=res[i-1]+res[i-2];
                }
            }
        }
        return res[n];
    }
};