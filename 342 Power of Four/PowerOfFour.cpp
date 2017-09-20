class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num<=0) return false;
        int t=num;
        while (t>1) {
            t>>=2;
        }
        return t==1 && !(num&(num-1));
    }
};