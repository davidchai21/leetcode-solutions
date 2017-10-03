class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string> > res;
        unordered_map<string,vector<string> > m;
        for (string a:strings) {
            m[helper(a)].push_back(a);
        }
        for (auto p:m) {
            res.push_back(p.second);
        }
        return res;
    }
    string helper(string a) {
        char t=a[0];
        string res="";
        for (int i=0;i<a.size();i++) {
            int l=a[i]-t;
            l=l<0?l+26:l;
            res+='a'+l;
        }
        return res;
    }
};