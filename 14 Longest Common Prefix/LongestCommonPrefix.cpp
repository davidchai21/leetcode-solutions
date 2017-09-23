class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string res="";
        if (n==0) return res;
        for (int i=0;i<strs[0].size();i++)
        {
            char t=strs[0][i];
            for (int j=1;j<n;j++)
            {
                if (strs[j][i]!=t) return res;
            }
            res+=t;
        }
        return res;
    }
};