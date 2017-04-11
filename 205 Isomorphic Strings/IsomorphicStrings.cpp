class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size()!=t.size()) return false;
        vector<char> t1(255,0);
        vector<char> t2(255,0);
        for (int i=0;i<s.size();i++)
        {
            if (t1[s[i]-1]==0) t1[s[i]-1]=t[i];
            else
            {
                if (t1[s[i]-1]!=t[i]) return false;
            }
            if (t2[t[i]-1]==0) t2[t[i]-1]=s[i];
            else
            {
                if (t2[t[i]-1]!=s[i]) return false;
            }
        }
        return true;
    }
};