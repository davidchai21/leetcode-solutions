class Solution {
public:
    bool hasAlternatingBits(int n) {
        if (n<=0) return false;
        int p=n&1;
        n>>=1;
        while (n) {
            if ((n&1)^p==0) return false; 
            p^=1;
            n>>=1;
        }
        return true;
    }
};