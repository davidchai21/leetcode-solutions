class Solution {
public:
    int lastRemaining(int n) {
        if (n<3) return n;
        if (n%2) return lastRemaining(n-1);
        return (1+n/2-lastRemaining(n/2))*2;
    }
};