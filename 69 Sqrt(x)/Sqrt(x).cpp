class Solution {
public:
    int mySqrt(int x) {
        if (x<2) return x;
        long r=x;
        while (r*r>x)
        {
            r=(x/r+r)/2;
        }
        return r;
    }
};