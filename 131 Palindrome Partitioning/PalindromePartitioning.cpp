class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        vector<string> t;
        helper(res,t,0,s);
        return res;
    }
    void helper(vector<vector<string> >& res, vector<string>& t, int pos, string s) {
        if (pos>=s.size()) {
            res.push_back(t);
            return;
        }
        for (int i=pos;i<s.size();i++) {
            if (is(s,pos,i)) {
                t.push_back(s.substr(pos,i+1-pos));
                helper(res,t,i+1,s);
                t.pop_back();
            }
        }
    }
    bool is(string s, int a, int b) {
        while (a<b) {
            if (s[a++]!=s[b--]) return false;
        }
        return true;
    }
};