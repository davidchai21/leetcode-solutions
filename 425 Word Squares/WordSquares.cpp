class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n=words[0].size();
        s.resize(n);
        for (string w:words) {
            for (int i=0;i<n;i++) {
                m[w.substr(0,i)].push_back(w);
            }
        }
        helper(0,n);
        return res;
    }
    void helper(int index, const int n) {
        if (index==n) {
            res.push_back(s);
            return;
        }
        string prefix="";
        for (int i=0;i<index;i++) {
            prefix+=s[i][index];
        }
        for (string p:m[prefix]) {
            s[index]=p;
            helper(index+1,n);
        }
    }
private:
    vector<string> s;
    vector<vector<string> > res;
    unordered_map<string, vector<string> > m;
};