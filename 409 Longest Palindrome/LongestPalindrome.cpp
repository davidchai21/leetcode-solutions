//#include <map>
class Solution {
public:
    int longestPalindrome(string s) {
        if (s.size()<2) return s.size();
        unordered_map<char,int> m;
        for (char a:s) m[a]++;
        int odd=0;
        int res=0;
        for (auto it=m.begin();it!=m.end();it++)
        {
            if (it->second%2)
            {
                odd=1;
                res+=it->second-1;
            }
            else res+=it->second;
        }
        return res+odd;
    }
};