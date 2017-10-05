class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if (n<2) return 0;
        vector<int> buy(n,0);
        vector<int> idle(n,0);
        vector<int> sell(n,0);
        buy[0]=-prices[0];
        for (int i=1;i<n;i++) {
            buy[i]=max(buy[i-1],idle[i-1]-prices[i]);
            idle[i]=sell[i-1];
            sell[i]=max(buy[i-1]+prices[i],sell[i-1]);
        }
        return sell[n-1];
    }
};