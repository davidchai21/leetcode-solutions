class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        unordered_map<string,int> m;
        for (string a:strs) m[a]++;
        vector<pair<string,int> > t;
        for (auto it=m.begin();it!=m.end();it++)
        {
            t.push_back(*it);
        }
        sort(t.begin(),t.end(),[](pair<string,int> a, pair<string,int> b){return a.first.size()>b.first.size();});
        for (int i=0;i<t.size();i++)
        {
            if (t[i].second==1)
            {
                int j=0;
                for (;j<i;j++)
                {
                    if (substr(t[i].first,t[j].first)) break;
                }
                if (j==i) return t[i].first.size();
            }
        }
        return -1;
    }
private:
    inline bool substr(string a, string b) // if a is a substring of b?
    {
        int m=a.size();
        int n=b.size();
        if (m>n) return false;
        int i=0;
        int j=0;
        while (i<m && j<n)
        {
            if (a[i]==b[j]) i++;
            j++;
        }
        if (i==m) return true;
        else return false;
    }
};