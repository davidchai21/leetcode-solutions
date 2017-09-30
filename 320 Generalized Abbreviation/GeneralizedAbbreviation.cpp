class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        res.push_back(word);
        helper(word,res,0);
        return res;
    }
    void helper(string& word, vector<string>& res, int pos) {
        for (int i=pos;i<word.size();i++) {
            for (int j=1;i+j<=word.size();j++) {
                string t=word.substr(0,i)+to_string(j)+word.substr(i+j);
                res.push_back(t);
                helper(t,res,i+1+to_string(j).size());
            }
        }
    }
};