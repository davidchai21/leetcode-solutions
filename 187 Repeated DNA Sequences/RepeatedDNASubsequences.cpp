class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int,int> m;
        vector<string> res;
        int v=0;
        int n=s.size();
        if (n<10) return res;
        for (int i=0;i<9;i++) {
            v=(v<<3)|(s[i]&7);
        }
        for (int i=9;i<n;i++) {
            v=(v<<3)&(0x3FFFFFFF)|(s[i]&7);
            if (m[v]++==1) {
                res.push_back(s.substr(i-9,10));
            }
        }
        return res;
    }
};