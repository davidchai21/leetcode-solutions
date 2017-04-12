class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> m;
        //int length=0;
        //for (int i=0;i<wall[0].size();i++) length+=wal[0][i];
        for (int i=0;i<wall.size();i++)
        {
            int s=0;
            for (int j=0;j<wall[i].size()-1;j++)
            {
                s+=wall[i][j];
                m[s]++;
            }
        }
        int max=0;
        for (auto it=m.begin();it!=m.end();it++)
        {
            if (max<it->second) max=it->second;
        }
        return wall.size()-max;
    }
};