class Solution {
public:
    bool isHappy(int n) {
        if (n<=0) return false;
        while (n>10) 
        {
            int t=0;
            while (n)
            {t+=(n%10)*(n%10);n/=10;}
            n=t;
        }
        return (n==1 || n==7 || n==10);
    }
};