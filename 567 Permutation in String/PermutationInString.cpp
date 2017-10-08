class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l=s1.size();
        if (l>s2.size()) return false;
        vector<int> a(256,0);
        vector<int> b(256,0);
        for (char t:s1) a[t]++;
        for (int i=0;i<l;i++) b[s2[i]]++;
        for (int i=0;i<s2.size()-l;i++) {
            if (a==b) return true;
            b[s2[i]]--;
            b[s2[i+l]]++;
        }
        if (a==b) return true;
        return false;
    }
};