class Solution {
public:
    int integerReplacement(long n) {
        if (n == 1) return 0;
        return ((n % 2) ? min(integerReplacement(n + 1), integerReplacement(n-1)) : integerReplacement(n / 2)) + 1;
    }
};