class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res;
        int c=K;
        for (int i=S.size()-1;i>=0;i--)
        {
            if (S[i]!='-')
            {
                if (c!=0)
                {
                    res=(char)toupper(S[i])+res;
                    c--;
                }
                else
                {
                    c=K-1;
                    res="-"+res;
                    res=(char)toupper(S[i])+res;
                }
            }
        }
        return res;
    }
};