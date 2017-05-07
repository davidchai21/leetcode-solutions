class Solution {
public:
    int integerBreak(int n) {
        if (n<4) return n-1;
        int sum=1;
        while (n>4)
        {
            sum*=3;
            n-=3;
        }
        return sum*n;
    }
};