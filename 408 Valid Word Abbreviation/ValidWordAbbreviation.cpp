class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i=0;
        string p="";
        while (i<abbr.size())
        {
            int n=0;
            while (i<abbr.size() && isdigit(abbr[i])) {
                if (abbr[i]=='0' && n==0) return false;
                n=n*10+abbr[i]-'0';
                if (n>word.size()) return false;
                i++;
            }
            while (n--) p+='*';
            while (i<abbr.size() && !isdigit(abbr[i])) {
                p+=abbr[i];
                i++;
            }
        }
        if (p.size()!=word.size()) return false;
        for (int i=0;i<p.size();i++)
        {
            if (p[i]=='*') continue;
            else if (p[i]!=word[i]) return false;
        }
        return true;
    }
};