class Solution {
public:
    bool judgeSquareSum(int c) {
        int n=sqrt(c);
        for (int i=n/2;i<=n;i++)
        {
            if (check(c-i*i)) return true;
        }
        return false;
    }
    bool check(int a) {
        int n=sqrt(a);
        return n*n==a;
    }
};