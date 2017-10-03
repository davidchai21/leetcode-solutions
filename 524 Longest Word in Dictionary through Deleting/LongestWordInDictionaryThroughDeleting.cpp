class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        unordered_map<int,vector<string> > m;
        vector<string> res;
        int l=0;
        for (string a:d) {
            if (check(a,s)) {
                if (l<a.size()) {
                    res.clear();
                    l=a.size();
                    res.push_back(a);
                }
                else if (l==a.size()) res.push_back(a);
            }
        }
        if (l==0) return "";
        set<string> st(res.begin(),res.end());
        return *st.begin();
    }
    bool check(string a, string s) {
        int j=0;
        for (int i=0;i<s.size();i++) {
            if (a[j]==s[i]) j++;
        }
        return j==a.size();
    }
};