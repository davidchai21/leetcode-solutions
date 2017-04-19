class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        for (char a:digits)
        {
            res=helper(res,a);
        }
        return res;
    }
private:
    vector<string> helper(vector<string>& res, char a)
    {
        if (a=='0' || a=='1') return res;
        vector<string> t;
        if (res.empty()) res.push_back("");
        for (int i=0;i<res.size();i++)
        {
            for (int j=0;j<s[a-'0'-2].size();j++)
            {
                t.push_back(res[i]+s[a-'0'-2][j]);
            }
        }
        return t;
    }
    string s[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
};