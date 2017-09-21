class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size()<2) return false;
        string t=(s+s).substr(1,2*s.size()-2);
        return t.find(s)!=string::npos;
    }
};