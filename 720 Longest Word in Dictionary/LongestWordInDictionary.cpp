class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        unordered_set<string> m;
        string res="";
        for (int i=0;i<words.size();i++) {
            if (words[i].size()==1 || m.find(words[i].substr(0,words[i].size()-1))!=m.end()) {
                res=res.size()<words[i].size()?words[i]:res;
                m.insert(words[i]);
            }
        }
        return res;
    }
};