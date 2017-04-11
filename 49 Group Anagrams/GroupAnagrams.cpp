class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string> > m;
        for (string a:strs)
        {
            string t=a;
            sort(t.begin(),t.end());
            m[t].insert(a);
        }
        vector<vector<string> > res;
        for (auto a:m)
        {
            vector<string> t;
            for (string l:a.second)
            {
                t.push_back(l);
            }
            res.push_back(t);
        }
        return res;
    }
};