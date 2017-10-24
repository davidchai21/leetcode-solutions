class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if (n<1) return -1;
        vector<int> res(amount+1,amount+1);
        res[0]=0;
        for (int i=1;i<=amount;i++) {
            for (int c:coins) {
                if (i-c>=0) {
                    res[i]=min(res[i-c]+1,res[i]);
                }
            }
        }
        return res[amount]==amount+1?-1:res[amount];
    }
};