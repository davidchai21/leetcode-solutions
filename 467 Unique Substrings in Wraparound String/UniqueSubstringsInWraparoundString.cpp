class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> s(26,0);
        int res=0;
        int len=0;
        for (int i=0;i<p.size();i++) {
            int cur=p[i]-'a';
            if (i>0 && p[i-1]!=(cur+25)%26+'a') len=0;
            if (++len>s[cur]) {
                res+=len-s[cur];
                s[cur]=len;
            }
        }
        return res;
    }
};