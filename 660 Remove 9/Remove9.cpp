class Solution {
public:
    int newInteger(int n) {
        int res=0;
        int times=1;
        while (n) {
            res+=times*(n%9);
            n/=9;
            times*=10;
        }
        return res;
    }
};