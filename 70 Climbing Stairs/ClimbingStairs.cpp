class Solution {
public:
    int climbStairs(int n) {
        if (n<3) return n;
        int pre=1;
        int cur=2;
        for (int i=2;i<n;i++)
        {
            int t=pre+cur;
            pre=cur;
            cur=t;
        }
        return cur;
    }
};