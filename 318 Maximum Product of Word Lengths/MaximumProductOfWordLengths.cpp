class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res=0;
        unordered_map<int,int> m;
        int n=words.size();
        if (n==0) return res;
        for (string s:words) {
            int mask=0;
            for (char a:s) {
                mask |= 1<<(a-'a');
            }
            m[mask]=max(m[mask],(int)s.size());
            for (auto t:m) {
                if (!(t.first&mask)) res=max(res,m[mask]*t.second);
            }
        }
        return res;
    }
};