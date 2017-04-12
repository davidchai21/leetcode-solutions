class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        string res="";
        for (char a:s) m[a]++;
        vector<string> r(s.size()+1,"");
        for (auto i:m)
        {
            r[i.second].append(i.second,i.first);
        }
        for (int i=s.size();i>=0;i--)
        {
            if (!r[i].empty()) res.append(r[i]);
        }
        return res;
    }
};