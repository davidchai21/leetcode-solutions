class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0;
        int j=0;
        int res=0;
        while (i<s.size() && j<g.size())
        {
            if (g[j]<=s[i])
            {
                i++; j++;
                res++;
            }
            else
            {
                i++;
            }
        }
        return res;
    }
};