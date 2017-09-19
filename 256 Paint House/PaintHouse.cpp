class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.size()<=0) return 0;
        vector<int> res(costs[0].begin(),costs[0].end());
        for (int i=1;i<costs.size();i++)
        {
            int a=costs[i][0]+min(res[1],res[2]);
            int b=costs[i][1]+min(res[0],res[2]);
            int c=costs[i][2]+min(res[1],res[0]);
            res[0]=a;
            res[1]=b;
            res[2]=c;
        }
        return min(min(res[0],res[1]),res[2]);
    }
};