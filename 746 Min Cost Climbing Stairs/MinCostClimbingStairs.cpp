class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int high=cost[1];
        int low=cost[0];
        for (int i=2;i<cost.size();i++) {
            int t=cost[i]+min(high,low);
            low=high;
            high=t;
        }
        return min(high,low);
    }
};