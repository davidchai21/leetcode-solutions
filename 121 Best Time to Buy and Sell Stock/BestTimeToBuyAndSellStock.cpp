class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<2) return 0;
        int a=prices[0];
        int res=0;
        for (int i=1;i<prices.size();i++)
        {
            if (prices[i]<a) a=prices[i];
            else
            {
                res=max(res,prices[i]-a);
            }
        }
        return res;
    }
};