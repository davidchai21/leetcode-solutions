class Solution {
public:
    vector<int> findPermutation(string s) {
        stack<int> m;
        vector<int> res;
        int i=1;
        int n=s.size()+1;
        while (i<=n) {
            if (s[i-1]=='D') m.push(i);
            else {
                res.push_back(i);
                while (!m.empty()) {
                    res.push_back(m.top());
                    m.pop();
                }
            }
            i++;
        }
        while (!m.empty()) {
            res.push_back(m.top());
            m.pop();
        }
        return res;
    }
};