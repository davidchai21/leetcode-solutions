class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.size()<p.size()) return res;
        vector<int> a(26,0);
        vector<int> w(26,0);
        for (int i=0;i<p.size();i++)
        {
            a[p[i]-'a']++;
            w[s[i]-'a']++;
        }
        if (a==w) res.push_back(0);
        
        for (int i=0;i<s.size()-p.size();i++)
        {
            --w[s[i]-'a'];
            ++w[s[i+p.size()]-'a'];
            if (a==w) res.push_back(i+1);
        }
        return res;
    }
};