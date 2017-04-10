class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (!amount) return 1;
        if (!coins.size()) return 0;
        vector<int> res(amount+1,0);
        res[0]=1;
        for (int i=0;i<coins.size();i++)
        {
            for (int j=coins[i];j<=amount;j++)
            {
                res[j]+=res[j-coins[i]];
            }
        }
        return res[amount];
    }
};