class Solution {
public:
    double myPow(double x, int n) {
        if (n==0) return 1;
        double res=1;
        if (n<0) {
            if (n==INT_MIN) {
                n++;
                res*=1/x;
            }
            x=1/x;
            n=-n;
        }
        while (n) {
            if (n%2) res*=x;
            n>>=1;
            x*=x;
        }
        return res;
    }
};