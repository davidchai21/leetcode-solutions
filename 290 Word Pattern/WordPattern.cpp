class Solution {
public:
    bool wordPattern(string pattern, string str) {
        // must build 2 maps to compare from either side.
        vector<string> s;
        string t;
        istringstream is(str);
        while (is>>t)
        {
            s.push_back(t);
        }
        if (pattern.size()!=s.size()) return false;
        unordered_map<char,string> m1;
        unordered_map<string,char> m2;
        for (int i=0;i<s.size();i++)
        {
            if (m1[pattern[i]]=="") m1[pattern[i]]=s[i];
            else if (m1[pattern[i]]!=s[i]) return false;
            if (m2[s[i]]==0) m2[s[i]]=pattern[i];
            else if (m2[s[i]]!=pattern[i]) return false;
        }
        return true;
    }
};