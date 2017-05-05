class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend==INT_MIN && divisor==-1)) return INT_MAX;
        int sign=((dividend<0)^(divisor<0))?-1:1;
        int res=0;
        long long a=labs(dividend);
        long long b=labs(divisor);
        while (a>=b)
        {
            long long times=b;
            long long bit=1;
            while ((times<<1)<=a)
            {
                times<<=1;
                bit<<=1;
            }
            a-=times;
            res+=bit;
        }
        return (sign>0)?res:-res;
    }
};