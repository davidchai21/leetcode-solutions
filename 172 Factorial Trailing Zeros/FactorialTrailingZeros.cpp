class Solution {
public:
    int trailingZeroes(int n) {
        long i=5;
        long sum=0;
        while (i<=n)
        {
            sum+=n/i;
            i*=5;
        }
        return sum;
    }
};