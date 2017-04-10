class Solution {
public:
    int countSegments(string s) {
        if (s.size()==0) return 0;
        int res=0;
        int i=0;
        int n=s.size();
        bool flag=false;
        while (i<n)
        {
            if (s[i]!=' ')
            {
                if (!flag)
                {
                    flag=true;
                    res++;
                }
            }
            else
            {flag=false;}
            i++;
        }
        if (!flag && s[i-1]!=' ') res++;
        return res;
    }
};