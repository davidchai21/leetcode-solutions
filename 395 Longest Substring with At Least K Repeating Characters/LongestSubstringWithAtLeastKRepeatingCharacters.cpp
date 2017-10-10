class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.empty() || s.size()<k) return 0;
        if (k==0) return s.size();
        vector<int> c(256,0);
        for (char a:s) c[a]++;
        for (int i=0;i<s.size();i++) {
            if (c[s[i]]<k) {
                istringstream ss(s);
                string t="";
                int res=0;
                while (getline(ss,t,s[i])) {
                    res=max(res,longestSubstring(t,k));
                }
                return res;
            }
        }
        return s.size();
    }
};