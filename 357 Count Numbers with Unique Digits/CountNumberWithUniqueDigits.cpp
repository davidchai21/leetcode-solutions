class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n==0) return 1;
        if (n==1) return 10;
        int sum=0;
        if (n<11)
        {
            sum=9;
            for (int i=9;i>10-n;i--)
            {
                sum*=i;
            }
        }
        return sum+countNumbersWithUniqueDigits(n-1);
    }
};