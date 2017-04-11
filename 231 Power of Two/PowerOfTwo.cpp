class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0) return false;
        int res=0;
        while (n)
        {
            n&=n-1;
            res++;
        }
        return (res==1);
    }
};