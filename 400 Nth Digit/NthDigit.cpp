class Solution {
public:
    int findNthDigit(int n) {
        long base=9;
        long digits=1;
        while (n-base*digits>0)
        {
            n-=base*digits;
            base*=10;
            digits++;
        }
        long a=pow(10,digits-1);
        if (n%digits)
        {
            a+=n/digits;
        }
        else
        {
            a+=n/digits-1;
        }
        int i=(n%digits)==0?digits:n%digits;
        for (;i<digits;i++)
        {
            a/=10;
        }
        return a%10;
    }
};