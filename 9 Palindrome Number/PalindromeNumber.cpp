class Solution {
public:
    bool isPalindrome(int x) {
        if (x==0) return true;
        if (x<0 || x%10==0) return false;
        int n=log10(x);
        while(n>0)
        {
            if (x%10!=(int)(x/pow(10,n))%10) return false;
            x/=10;
            n-=2;
        }
        return true;
    }
};