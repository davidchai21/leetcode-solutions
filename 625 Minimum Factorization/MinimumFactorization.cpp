class Solution {
public:
    int smallestFactorization(int a) {
        if (a<10) return a;
        long long res=0;
        int k=9;
        long long base=1;
        while (k>=2) {
            while (a%k==0) {
                res=base*k+res;
                if (res>=INT_MAX) return 0;
                base*=10;
                a/=k;
            }
            k--;
        }
        return a==1?res:0;
    }
};