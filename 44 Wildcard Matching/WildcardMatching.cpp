class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        int star=-1, match, i=0, j=0;
        while (i<m)
        {
            if (s[i]==p[j]||p[j]=='?') {i++;j++;}
            else if (p[j]=='*') 
            {
                star=j++;
                match=i;
            }
            else if (star!=-1)
            {
                j=star+1;
                i=++match;
            }
            else return false;
        }
        while (p[j]=='*') j++;
        return !p[j];
    }
};