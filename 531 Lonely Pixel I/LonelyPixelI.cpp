class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        unordered_map<int,int> m,n;
        int res=0;
        if (picture.size()==0 || picture[0].size()==0) return res;
        for (int i=0;i<picture.size();i++)
        {
            for (int j=0;j<picture[0].size();j++)
            {
                if (picture[i][j]=='B') {
                    m[i]++;
                    n[j]++;
                }
            }
        }
        vector<int> row,column;
        for (auto it=m.begin();it!=m.end();it++) {
            if (it->second==1) row.push_back(it->first);
        }
        for (auto it=n.begin();it!=n.end();it++) {
            if (it->second==1) column.push_back(it->first);
        }
        for (int i=0;i<row.size();i++)
        {
            for (int j=0;j<column.size();j++)
            {
                if (picture[row[i]][column[j]]=='B') res++;
            }
        }
        return res;
    }
};