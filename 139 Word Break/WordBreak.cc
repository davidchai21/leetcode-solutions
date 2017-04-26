class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string> t;
        for (string a:wordDict) t.insert(a);
        vector<bool> res(n+1,false);
        res[0]=true;
        for (int i=1;i<=n;i++)
        {
            for (int j=i-1;j>=0;j--)
            {
                if (res[j])
                {
                    if (t.find(s.substr(j,i-j))!=t.end())
                    {res[i]=true; break;}
                }
            }
        }
        return res[n];
    }
};