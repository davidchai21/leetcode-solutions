class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,string> parent;
        unordered_map<string,string> name;
        for (int i=0;i<accounts.size();i++) {
            for (int j=1;j<accounts[i].size();j++) {
                parent[accounts[i][j]]=accounts[i][j];
                name[accounts[i][j]]=accounts[i][0];
            }
        }
        for (int i=0;i<accounts.size();i++) {
            string p=find(parent,accounts[i][1]);
            for (int j=2;j<accounts[i].size();j++) parent[find(parent,accounts[i][j])]=p;
        }
        unordered_map<string,set<string> > m;
        for (int i=0;i<accounts.size();i++) {
            for (int j=1;j<accounts[i].size();j++) {
                m[find(parent,accounts[i][j])].insert(accounts[i][j]);
            }
        }
        vector<vector<string> > res;
        for (auto p:m) {
            vector<string> t;
            t.push_back(name[p.first]);
            for (string l:p.second) t.push_back(l);
            res.push_back(t);
        }
        return res;
    }
private:
    string find(unordered_map<string,string>& m, string s) {
        if (m[s]!=s) {
            m[s]=find(m,m[s]);
        }
        return m[s];
    }
};